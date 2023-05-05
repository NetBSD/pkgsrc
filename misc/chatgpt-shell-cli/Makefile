# $NetBSD: Makefile,v 1.2 2023/05/05 14:04:18 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}
PKGNAME=		${GITHUB_PROJECT:tl}-0.0.20230505
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=0xacx/}
GITHUB_PROJECT=		chatGPT-shell-cli
GITHUB_TAG=		2e25138caaad77b59edb9936798a92ae80a4e0cd

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/0xacx/chatGPT-shell-cli/
COMMENT=		Shell script to use OpenAI's ChatGPT and DALL-E
LICENSE=		mit

DEPENDS+=		curl-[0-9]*:../../www/curl
DEPENDS+=		jq-[0-9]*:../../devel/jq

USE_LANGUAGES=		# none
USE_TOOLS+=		bash:run
NO_BUILD=		yes
INSTALLATION_DIRS=	bin

REPLACE_BASH=		chatgpt.sh

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
DEPENDS+=		xdg-utils-[0-9]*:../../misc/xdg-utils
SUBST_CLASSES+=		open
SUBST_STAGE.open=	do-configure
SUBST_FILES.open=	chatgpt.sh
SUBST_SED.open=		-e 's|open \("$${image_url}"\)|xdg-open \1|g'
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/chatgpt.sh ${DESTDIR}${PREFIX}/bin/chatgpt

.include "../../mk/bsd.pkg.mk"
