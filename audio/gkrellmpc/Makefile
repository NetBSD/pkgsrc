# $NetBSD: Makefile,v 1.15 2024/05/29 16:31:20 adam Exp $
DISTNAME=	gkrellmpc-0.1_beta10
PKGREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=simark/}
GITHUB_PROJECT=	gkrellm-gkrellmpc
GITHUB_TAG=	da1a6d988162c248e0c86a9af6db8f9a5a094bc8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simark/gkrellm-gkrellmpc
COMMENT=	GKrellM plugin to control musicpd
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake

.include "options.mk"

INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale
INSTALLATION_DIRS+=	lib/gkrellm2/plugins
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
do-install:
	${INSTALL_LIB} "${WRKSRC}/gkrellmpc.so" \
		"${DESTDIR}${PREFIX}/lib/gkrellm2/plugins"
	${INSTALL_DATA} "${WRKSRC}/README.txt" \
		"${DESTDIR}${PREFIX}/share/doc/${PKGBASE}"

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
