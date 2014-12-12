# $NetBSD: Makefile,v 1.17 2014/12/12 06:45:34 mef Exp $

DISTNAME=	dbench-4.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://samba.org/ftp/tridge/dbench/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/tridge/dbench/README
COMMENT=	Simulation of the Ziff-Davis netbench benchmark
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS=	autoconf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	DB_LDFLAGS="-lrt" TB_LDFLAGS="-lsocket -lnsl"
.endif

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			datadir=${DESTDIR}${PREFIX}/share/dbench \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/dbench

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	dbench.1
SUBST_SED.path=		-e 's|/usr/share/|${PREFIX}/share/|g'

INSTALLATION_DIRS=	share/doc/dbench

pre-configure:
	(cd ${WRKSRC}; autoconf)

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dbench

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
