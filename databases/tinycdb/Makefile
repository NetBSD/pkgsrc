# $NetBSD: Makefile,v 1.8 2013/02/27 12:38:12 ryoon Exp $
#

DISTNAME=		tinycdb-0.78
CATEGORIES=		databases
MASTER_SITES=		http://www.corpit.ru/mjt/tinycdb/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://www.corpit.ru/mjt/tinycdb.html
COMMENT=		Create and read constant databases
LICENSE=		public-domain

CONFLICTS+=		cdb-[0-9]*

USE_LIBTOOL=		yes
USE_LANGUAGES=		c

MAKE_FILE=		BSDmakefile

PKGCONFIG_OVERRIDE+=	libcdb.pc

INSTALLATION_DIRS+=	lib/pkgconfig

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	libcdb.pc
SUBST_VARS.paths=	PREFIX
SUBST_MESSAGE.paths=	Configuring pkgsrc paths.

post-install:
	${INSTALL_DATA} ${WRKSRC}/libcdb.pc \
			${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
