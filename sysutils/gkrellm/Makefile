# $NetBSD: Makefile,v 1.1.1.1 2001/03/13 17:53:29 zuntum Exp $
#

DISTNAME=	gkrellm-1.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://newweb.wt.net/~billw/

MAINTAINER=	anthony.mallet@ficus.yi.org
HOMEPAGE=	http://gkrellm.net/
COMMENT=	GTK based system monitor

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	pth-*:../../devel/pth

USE_X11BASE=	yes
USE_GMAKE=	yes

BINGRP=         kmem
BINMODE=        2755

ALL_TARGET=	netbsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gkrellm ${PREFIX}/bin/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gkrellm
	cd ${WRKSRC} && ${INSTALL_DATA} COPYRIGHT README Themes.html	\
		${PREFIX}/share/doc/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/include/gkrellm
	cd ${WRKSRC}/src && ${INSTALL_DATA} gkrellm.h			\
		gkrellm_public_proto.h gkrellm_private_proto.h 		\
		${PREFIX}/include/gkrellm

.include "../../mk/bsd.pkg.mk"
