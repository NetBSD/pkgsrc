# $NetBSD: Makefile,v 1.53 2004/05/22 21:46:57 jmmv Exp $
#

PKGNAME=	kaffe-${KAFFE_VERSION}
PKGREVISION=	1
COMMENT=	Virtual machine capable of running Java(tm) code

USE_X11=	yes

CONFLICTS=	kaffe-nox11-[0-9]*
PLIST_SUBST+=	WITH_X11=

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
