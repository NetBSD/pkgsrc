# $NetBSD: Makefile,v 1.1.1.1 2000/05/12 20:41:40 sakamoto Exp $
#

DISTNAME=	jpnfont
CATEGORIES=	fonts japanese

DEPENDS+=	acroread-font-share-4.0:../../fonts/acroread-font-share

WRKSRC=		${WRKDIR}/JPNKIT
TAR_FILE=	${WRKSRC}/LANGJPN.TAR

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_MSG} "==============================================================="; \
		${ECHO_MSG} "  Be required to register with Adobe"; \
		${ECHO_MSG} "  before downloading the Japanese font pack."; \
		${ECHO_MSG} "  You should manual-fetch Japanese pack of \"Asian Font Packs\""; \
		${ECHO_MSG} "  to ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} from"; \
		${ECHO_MSG} "    http://www.adobe.com/prodindex/acrobat/readstep.html"; \
		${ECHO_MSG} "==============================================================="; \
		${FALSE}; \
	 fi

.include "../acroread-font-share/Makefile.common"
