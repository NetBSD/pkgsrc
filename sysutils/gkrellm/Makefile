# $NetBSD: Makefile,v 1.3 2001/06/11 19:44:30 zuntum Exp $
#

DISTNAME=	gkrellm-1.0.8
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/

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

.include "../../mk/bsd.pkg.mk"
