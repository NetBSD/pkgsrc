# $NetBSD: Makefile,v 1.2 2004/03/12 04:56:49 snj Exp $
#

DISTNAME=	gkrellm-1.2.13
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	anthony.mallet@ficus.yi.org
HOMEPAGE=	http://gkrellm.net/
COMMENT=	GTK based system monitor

BUILD_USES_MSGFMT=	YES

OSVERSION_SPECIFIC=	YES
USE_BUILDLINK3=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

ALL_TARGET=		netbsd
INSTALL_TARGET=		install_netbsd

MAKE_ENV+=	PTHREAD_INC="-I${LOCALBASE}/include"
MAKE_ENV+=	EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm/themes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
