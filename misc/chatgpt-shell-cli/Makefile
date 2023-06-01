# $NetBSD: Makefile,v 1.3 2023/06/01 07:04:10 wiz Exp $

DISTNAME=		chatgpt-shell-cli-0.0.20230516
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=0xacx/}
GITHUB_PROJECT=		chatGPT-shell-cli
GITHUB_TAG=		926587a2234b8ae3754a1db9715f4636205159dc

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
