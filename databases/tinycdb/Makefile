# $NetBSD: Makefile,v 1.9 2020/01/26 17:30:54 rillig Exp $
#

DISTNAME=		tinycdb-0.78
CATEGORIES=		databases
MASTER_SITES=		http://www.corpit.ru/mjt/tinycdb/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.corpit.ru/mjt/tinycdb.html
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
