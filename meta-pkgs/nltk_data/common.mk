# $NetBSD: common.mk,v 1.3 2023/03/16 11:06:02 jperkin Exp $

MASTER_SITES=	https://github.com/nltk/nltk_data/raw/ee3fb3aecd8bce44a44e2303d679fe32c0ec437b/packages/${TYPE}/
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
