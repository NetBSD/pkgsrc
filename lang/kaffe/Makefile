# $NetBSD: Makefile,v 1.52 2004/04/06 16:59:36 xtraeme Exp $
#

PKGNAME=	kaffe-${KAFFE_VERSION}
COMMENT=	Virtual machine capable of running Java(tm) code

USE_X11=	yes

CONFLICTS=	kaffe-nox11-[0-9]*
PLIST_SUBST+=	WITH_X11=

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"

PREFIX=		${JVM_HOME}
