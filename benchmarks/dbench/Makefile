# $NetBSD: Makefile,v 1.12 2008/05/01 13:17:55 obache Exp $

DISTNAME=	dbench-3.04
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

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/dbench

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	dbench.1
SUBST_SED.path=		-e 's|/usr/share/|${PREFIX}/share/|g'

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/dbench
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dbench

.include "../../mk/bsd.pkg.mk"
