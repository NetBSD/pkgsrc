# $NetBSD: common.mk,v 1.1 2021/11/24 15:56:18 wiz Exp $

MASTER_SITES=	https://raw.githubusercontent.com/nltk/nltk_data/gh-pages/packages/${TYPE}/
EXTRACT_SUFX?=	.zip

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://www.nltk.org/data.html
COMMENT?=	Natural Language Toolkit (NLTK) Data

INSTALLATION_DIRS+=	share/nltk_data/${TYPE}

UNPACK?=	no

do-build:

.if ${UNPACK} == "no"
do-install:
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/share/nltk_data/${TYPE}
.else
USE_TOOLS+=	pax

do-install:
	cd ${WRKDIR} && ${PAX} -pp -rw ${DISTNAME} ${DESTDIR}${PREFIX}/share/nltk_data/${TYPE}/
.endif
