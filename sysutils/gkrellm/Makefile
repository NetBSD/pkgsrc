# $NetBSD: Makefile,v 1.19.2.2 2002/06/30 06:24:14 jlam Exp $
#

DISTNAME=	gkrellm-1.2.11
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	anthony.mallet@ficus.yi.org
HOMEPAGE=	http://gkrellm.net/
COMMENT=	GTK based system monitor

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES

ALL_TARGET=		netbsd
INSTALL_TARGET=		install_netbsd

MAKE_ENV+=	PTHREAD_INC="-I${LOCALBASE}/include"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm/themes

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
