# $NetBSD: Makefile,v 1.8 2001/10/23 13:15:02 jlam Exp $
#

DISTNAME=	gkrellm-1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/

MAINTAINER=	anthony.mallet@ficus.yi.org
HOMEPAGE=	http://gkrellm.net/
COMMENT=	GTK based system monitor

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=	yes

ALL_TARGET=	netbsd
INSTALL_TARGET=	install_netbsd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../mk/x11.buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
