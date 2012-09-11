# $NetBSD: Makefile,v 1.15 2012/09/11 22:37:11 asau Exp $

DISTNAME=	dbench-3.04
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://samba.org/ftp/tridge/dbench/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/tridge/dbench/README
COMMENT=	Simulation of the Ziff-Davis netbench benchmark

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dbench

.include "../../mk/bsd.pkg.mk"
