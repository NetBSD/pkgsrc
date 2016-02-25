# $NetBSD: Makefile,v 1.18 2016/02/25 11:09:50 jperkin Exp $

DISTNAME=	dbench-4.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://samba.org/ftp/tridge/dbench/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/tridge/dbench/README
COMMENT=	Simulation of the Ziff-Davis netbench benchmark
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS=	autoconf

MAKE_ENV.SunOS+=	DB_LDFLAGS="-lrt" TB_LDFLAGS="-lsocket -lnsl"

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
