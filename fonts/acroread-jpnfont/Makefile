# $NetBSD: Makefile,v 1.3 2002/02/26 21:28:49 fredb Exp $
#

DISTNAME=	jpnfont
CATEGORIES=	fonts japanese

COMMENT=	Asian Font Packs for Acrobat Reader 4.0 (Japanese)

DEPENDS+=	acroread-font-share-4.0:../../fonts/acroread-font-share

WRKSRC=		${WRKDIR}/JPNKIT
TAR_FILE=	${WRKSRC}/LANGJPN.TAR

_FETCH_MESSAGE= \
	${ECHO} "======================================================="; \
	${ECHO} "  Be required to register with Adobe"; \
	${ECHO} "  before downloading the Japanese font pack."; \
	${ECHO} "  You should manual-fetch Japanese pack of \"Asian Font Packs\""; \
	${ECHO} "  to ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} from"; \
	${ECHO} "    http://www.adobe.com/prodindex/acrobat/readstep.html"; \
	${ECHO} "======================================================="

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${_FETCH_MESSAGE}; \
		${FALSE}; \
	 fi

fetch-list-one-pkg:
	@${ECHO} ${_FETCH_MESSAGE:Q}

.include "../acroread-font-share/Makefile.common"
