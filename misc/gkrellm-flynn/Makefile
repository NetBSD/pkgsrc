# $NetBSD: Makefile,v 1.1.1.1 2004/02/25 00:49:59 cube Exp $
#

DISTNAME=	gkrellflynn-0.8
PKGNAME=	${DISTNAME:S/gkrell/gkrellm-/}
CATEGORIES=	misc
MASTER_SITES=	http://horus.comlab.uni-rostock.de/flynn/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://horus.comlab.uni-rostock.de/flynn/
COMMENT=	GKrellM2 plugin that shows system load with a DooM marine

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
ALL_TARGET=	gkrellm2
INSTALL_TARGET=	installgkrellm2

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
