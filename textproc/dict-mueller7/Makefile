# $NetBSD: Makefile,v 1.17 2022/06/28 11:36:09 wiz Exp $

DISTNAME=	Mueller7GPL
PKGNAME=	dict-mueller7-1.2
PKGREVISION=	10
CATEGORIES=	textproc
MASTER_SITES=	http://dict.osdn.org.ua/
MASTER_SITES+=	http://mova.org/~cheusov/pub/dict-mueller/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://mueller-dic.chat.ru/
COMMENT=	English-Russian dictionary by Mueller for dictd
LICENSE=	gnu-gpl-v2

DEPENDS+=	dict-server>=1.9.14:../../textproc/dict-server

BUILD_DEPENDS+=	dict-server>=1.10.2:../../textproc/dict-server
BUILD_DEPENDS+=	p5-Unicode-Map8-[0-9]*:../../converters/p5-Unicode-Map8
BUILD_DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils # we need GNU fmt

WRKSRC=		${WRKDIR}/usr/local/share/dict

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		perl tar gzip
.if ${OPSYS} != "NetBSD"
USE_TOOLS+=		gsed
.endif

INSTALLATION_DIRS+=	share/dictd

pre-configure:
	cp files/mueller2utf8 files/to-dict ${WRKSRC}

do-build:
	cd ${WRKSRC} && \
	sh to-dict --src-data Mueller7GPL.koi mueller7.data > /dev/null && \
	${PREFIX}/bin/perl mueller2utf8 < mueller7.data > tmp_1 && \
	${PREFIX}/bin/dictfmt --utf8 -p --columns 0 \
		-s 'Mueller English-Russian Dictionary' \
		-u 'http://www.chat.ru/~mueller_dic' \
		--headword-separator ', ' mueller7 < tmp_1 && \
	${PREFIX}/bin/dictzip *.dict

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.dict.dz ${WRKSRC}/*.index \
		${DESTDIR}${PREFIX}/share/dictd

.include "../../mk/bsd.pkg.mk"
