# $NetBSD: Makefile,v 1.1 2021/02/20 21:08:38 ryoon Exp $

GITHUB_PROJECT=	rime-luna-pinyin
GITHUB_TAG=	19726ceca1b343d660382903d100f517bdc775ab
DISTNAME=	${GITHUB_PROJECT}-0.0.0.20210131
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=rime/}

COMMENT=	Rime input method engine data, luna-pinyin
LICENSE=	gnu-lgpl-v3

DEPENDS+=	rime-data-[0-9]*:../../meta-pkgs/rime-data

INSTALLATION_DIRS+=	share/rime-data

do-build:
	${CP} -r ${PREFIX}/share/rime-data/*.yaml ${WRKSRC}
	cd ${WRKSRC} && \
		${PREFIX}/bin/rime_deployer --build

do-install:
	${INSTALL_DATA} ${WRKSRC}/luna*.yaml \
		${DESTDIR}${PREFIX}/share/rime-data
	${INSTALL_DATA} ${WRKSRC}/pinyin.yaml \
		${DESTDIR}${PREFIX}/share/rime-data
	${CP} -r ${WRKSRC}/build ${DESTDIR}${PREFIX}/share/rime-data

.include "../../mk/bsd.pkg.mk"
