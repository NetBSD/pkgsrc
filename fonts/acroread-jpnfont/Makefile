# $NetBSD: Makefile,v 1.13 2007/12/01 03:57:28 rillig Exp $
#

DISTNAME=	jpnfont
PKGREVISION=	1
CATEGORIES=	fonts japanese

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 4.0 (Japanese)

DEPENDS+=	acroread-font-share>=4.0nb2:../../fonts/acroread-font-share

WRKSRC=		${WRKDIR}/JPNKIT
TAR_FILE=	${WRKSRC}/LANGJPN.TAR

INTERACTIVE_STAGE=	fetch

FETCH_MESSAGE=								\
	"Registration with Adobe is required before downloading"	\
	"the Japanese font pack.  You should manually fetch the"	\
	"\"Asian Font Packs\" to:"					\
	"    ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"			\
	"from:"								\
	"    http://www.adobe.com/prodindex/acrobat/readstep.html"

.include "../../fonts/acroread-font-share/Makefile.common"
