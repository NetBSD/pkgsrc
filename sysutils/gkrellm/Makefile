# $NetBSD: Makefile,v 1.16 2002/02/13 23:14:03 wiz Exp $
#

DISTNAME=	gkrellm-1.2.4
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/

MAINTAINER=	anthony.mallet@ficus.yi.org
HOMEPAGE=	http://gkrellm.net/
COMMENT=	GTK based system monitor

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES

ALL_TARGET=		netbsd
INSTALL_TARGET=		install_netbsd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm/themes

.include "../../graphics/imlib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
