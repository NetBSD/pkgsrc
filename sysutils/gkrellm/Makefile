# $NetBSD: Makefile,v 1.6 2001/08/29 22:41:21 jlam Exp $
#

DISTNAME=	gkrellm-1.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/

MAINTAINER=	anthony.mallet@ficus.yi.org
HOMEPAGE=	http://gkrellm.net/
COMMENT=	GTK based system monitor

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes

BINGRP=         kmem
BINMODE=        2755

ALL_TARGET=	netbsd

MAKE_ENV+=	LOCALEDIR="${LOCALBASE}/locale"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gkrellm ${PREFIX}/bin/gkrellm
	${INSTALL_MAN} ${WRKSRC}/gkrellm.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gkrellm
	cd ${WRKSRC} && ${INSTALL_DATA} COPYRIGHT README Themes.html	\
		${PREFIX}/share/doc/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/include/gkrellm
	cd ${WRKSRC}/src && ${INSTALL_DATA} gkrellm.h			\
		gkrellm_public_proto.h gkrellm_private_proto.h 		\
		${PREFIX}/include/gkrellm

.include "../../devel/pth/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
