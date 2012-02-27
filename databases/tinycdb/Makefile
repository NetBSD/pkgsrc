# $NetBSD: Makefile,v 1.6 2012/02/27 17:14:46 elric Exp $
#

DISTNAME=		tinycdb_0.77
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://www.corpit.ru/mjt/tinycdb/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.corpit.ru/mjt/tinycdb.html
COMMENT=		Create and read constant databases

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		cdb-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

BUILD_TARGET=		all sharedlib piclib
INSTALL_TARGET=		install install-piclib install-sharedlib

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	Makefile debian/libcdb.pc
SUBST_VARS.paths=	PREFIX PKG_SYSCONFDIR PKGMANDIR
SUBST_MESSAGE.paths=	Configuring pkgsrc paths.

PKGCONFIG_OVERRIDE+=	debian/libcdb.pc

INSTALLATION_DIRS+=	lib/pkgconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/debian/libcdb.pc \
			${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
