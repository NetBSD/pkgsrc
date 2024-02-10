# $NetBSD: Makefile,v 1.2 2024/02/10 09:45:45 ryoon Exp $

GITHUB_PROJECT=	rime-luna-pinyin
GITHUB_TAG=	79aeae200a7370720be98232844c0715f277e1c0
DISTNAME=	${GITHUB_PROJECT}-0.0.0.20230204
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
