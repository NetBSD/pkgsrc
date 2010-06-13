# $NetBSD: Makefile,v 1.18 2010/06/13 22:44:58 wiz Exp $
#

DISTNAME=	gkleds-0.8.2
PKGNAME=	${DISTNAME:S/^gk/gkrellm-/}
PKGREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	http://heim.ifi.uio.no/~oyvinha/files/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://heim.ifi.uio.no/~oyvinha/gkleds/
COMMENT=	GKrellM plugin that monitors CapsLock, NumLock and ScrollLock keys

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
