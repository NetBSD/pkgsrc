# $NetBSD: Makefile,v 1.21 2002/02/28 13:42:59 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/02/12 08:39:15 tg Exp
#

DISTNAME=       	icon.v940src
PKGNAME=		icon-9.4.0
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.arizona.edu/icon/index.htm
COMMENT=		The Icon programming language

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-i386 NetBSD-*-sparc

PLIST_SRC=		${PKGDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS=		ICON_WITH_GRAPHICS

ICON_WITH_GRAPHICS?=	YES

.if (${ICON_WITH_GRAPHICS} == "YES")
CONFIGURE_TARGET?=	X-Configure
PLIST_SRC+=		${PKGDIR}/PLIST.graphics
USE_X11=		yes
.else
CONFIGURE_TARGET?=	Configure
.endif

ALL_TARGET=		All

pre-build:
	${MKDIR} ${WRKSRC}/lib/icon

do-configure:
	cd ${WRKSRC}/config/unix/netbsd; \
	${SED} -e 's:@X11BASE@:${X11BASE}:g' define.h.graphics.in \
		> define.h.graphics
	cd ${WRKSRC}; ${MAKE} ${CONFIGURE_TARGET} name=netbsd

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} dest=${PREFIX} Install

.include "../../mk/bsd.pkg.mk"

