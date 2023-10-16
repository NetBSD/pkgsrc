# $NetBSD: Makefile,v 1.1 2023/10/16 14:04:53 ryoon Exp $

DISTNAME=	festival-freebsoft-utils-0.10
CATEGORIES=	audio
MASTER_SITES=	https://freebsoft.org/pub/projects/festival-freebsoft-utils/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://freebsoft.org/festival-freebsoft-utils
COMMENT=	Festival extensions and utilities for Speech Dispatcher
LICENSE=	gnu-gpl-v2

DEPENDS+=	festival-[0-9]*:../../audio/festival

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/festival/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.scm ${DESTDIR}${PREFIX}/share/festival/lib

.include "../../mk/bsd.pkg.mk"
