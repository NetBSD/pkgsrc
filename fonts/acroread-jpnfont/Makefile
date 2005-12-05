# $NetBSD: Makefile,v 1.10 2005/12/05 20:50:13 rillig Exp $
#

DISTNAME=	jpnfont
CATEGORIES=	fonts japanese

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 4.0 (Japanese)

DEPENDS+=	acroread-font-share-4.0:../../fonts/acroread-font-share

WRKSRC=		${WRKDIR}/JPNKIT
TAR_FILE=	${WRKSRC}/LANGJPN.TAR

INTERACTIVE_STAGE=	fetch

_FETCH_MESSAGE= \
	${ECHO} "======================================================="; \
	${ECHO} "  Be required to register with Adobe"; \
	${ECHO} "  before downloading the Japanese font pack."; \
	${ECHO} "  You should manual-fetch Japanese pack of \"Asian Font Packs\""; \
	${ECHO} "  to ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} from"; \
	${ECHO} "    http://www.adobe.com/prodindex/acrobat/readstep.html"; \
	${ECHO} "======================================================="

.include "../../fonts/acroread-font-share/Makefile.common"
