# $NetBSD: Makefile,v 1.13 2006/06/27 21:55:04 wiz Exp $
#

DISTNAME=	gkrellm-1.2.13
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gkrellm.net/
COMMENT=	GTK based system monitor

OSVERSION_SPECIFIC=	YES
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	YES

CONFLICTS+=	gkrellm-share>=2.0

BUILD_TARGET=		netbsd
INSTALL_TARGET=		install_netbsd

MAKE_ENV+=	PTHREAD_INC="-I${LOCALBASE}/include"
MAKE_ENV+=	EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_DATA_DIR} ${PREFIX}/share/gkrellm/themes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
