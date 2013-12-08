# $NetBSD: Makefile,v 1.6 2013/12/08 02:56:22 dholland Exp $
#

DISTNAME=	bsdav-1.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jakemsr.trancell.org/
COMMENT=	BSD Audio/Video library and tools

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-* DragonFly-*-*

USE_BSD_MAKEFILE=	yes
NO_CONFIGURE=		yes

MAKE_ENV+=		DIST=${WRKSRC}
MAKE_ENV+=		MKPICINSTALL=no
MAKE_ENV+=		MKSTATIC=no
MAKE_FLAGS+=		MKPROFILE=yes

BUILDLINK_TRANSFORM+=	rm:-Werror

AUTO_MKDIRS=		yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.bsdav
PKG_SUPPORTED_OPTIONS=	x11

PLIST_SRC=		${WRKDIR}/.PLIST_SRC

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
MAKE_ENV+=		BUILD_X11PROGS=yes
PLIST_SRC+=		PLIST.x11
.  include "../../x11/libXv/buildlink3.mk"
.endif

post-extract:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

.include "../../mk/bsd.pkg.mk"
