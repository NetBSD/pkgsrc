# $NetBSD: Makefile,v 1.2 2004/05/22 21:46:56 jmmv Exp $
#

PKGNAME=	kaffe-nox11-1.1.4
PKGREVISION=	1
COMMENT=	Virtual machine capable of running Java(tm) code (without X)

CONFIGURE_ARGS+=    --without-x

CONFLICTS=	kaffe-[0-9]*
PLIST_SUBST+=	WITH_X11='@comment '

.include "../kaffe/Makefile.common"
.include "../../mk/bsd.pkg.mk"
