# $NetBSD: Makefile,v 1.8 2003/07/17 21:36:44 grant Exp $
#

DISTNAME=	jpnfont
WRKSRC=		${WRKDIR}/JPNKIT
CATEGORIES=	fonts japanese

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 4.0 (Japanese)

DEPENDS+=	acroread-font-share-4.0:../../fonts/acroread-font-share

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

.include "../acroread-font-share/Makefile.common"
