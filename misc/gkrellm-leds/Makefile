# $NetBSD: Makefile,v 1.4 2004/10/03 00:12:58 tv Exp $
#

DISTNAME=	gkleds-0.8.1
PKGNAME=	${DISTNAME:S/^gk/gkrellm-/}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://heim.ifi.uio.no/~oyvinha/files/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://heim.ifi.uio.no/~oyvinha/article.php?2.0.0
COMMENT=	GKrellM plugin that monitors CapsLock, NumLock and ScrollLock keys

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
ALL_TARGET=	unix

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkleds.so ${PREFIX}/lib/gkrellm2/plugins

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
