# $NetBSD: common.mk,v 1.2 2021/11/24 17:26:15 wiz Exp $

MASTER_SITES=	https://raw.githubusercontent.com/nltk/nltk_data/gh-pages/packages/${TYPE}/
EXTRACT_SUFX?=	.zip

MAINTAINER?=	pkgsrc-users@NetBSD.org
HOMEPAGE?=	https://www.nltk.org/data.html
COMMENT?=	Natural Language Toolkit (NLTK) Data

INSTALLATION_DIRS+=	share/nltk_data/${TYPE}

UNPACK?=	no

RESTRICTED?=		Not investigated if this may be re-distributed.
NO_BIN_ON_CDROM?=	${RESTRICTED}
NO_SRC_ON_CDROM?=	${RESTRICTED}
NO_BIN_ON_FTP?=		${RESTRICTED}
NO_SRC_ON_FTP?=		${RESTRICTED}

do-build:

.if ${UNPACK} == "no"
do-install:
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/share/nltk_data/${TYPE}
.else
USE_TOOLS+=	pax

do-install:
	cd ${WRKDIR} && ${PAX} -pp -rw ${DISTNAME} ${DESTDIR}${PREFIX}/share/nltk_data/${TYPE}/
.endif
