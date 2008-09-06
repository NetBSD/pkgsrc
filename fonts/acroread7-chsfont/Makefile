# $NetBSD: Makefile,v 1.4 2008/09/06 20:50:02 wiz Exp $
#

DISTNAME=	chsfont
PKGREVISION=	1
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 7 (Chinese Simplified)

DEPENDS+=	acroread7-font-share>=7.0nb1:../../fonts/acroread7-font-share

WRKSRC=		${WRKDIR}/CHSKIT
TAR_FILE=	${WRKSRC}/LANGCHS.TAR

.include "../../fonts/acroread7-font-share/Makefile.common"
