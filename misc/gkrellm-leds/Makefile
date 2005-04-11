# $NetBSD: Makefile,v 1.7 2005/04/11 21:46:34 tv Exp $
#

DISTNAME=	gkleds-0.8.2
PKGNAME=	${DISTNAME:S/^gk/gkrellm-/}
CATEGORIES=	misc
MASTER_SITES=	http://heim.ifi.uio.no/~oyvinha/files/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://heim.ifi.uio.no/~oyvinha/gkleds/
COMMENT=	GKrellM plugin that monitors CapsLock, NumLock and ScrollLock keys

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/gkrellm2/plugins

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
