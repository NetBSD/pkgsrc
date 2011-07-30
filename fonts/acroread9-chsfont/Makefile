# $NetBSD: Makefile,v 1.1.1.1 2011/07/30 07:33:48 ryoon Exp $
#

DISTNAME=	chsfont
CATEGORIES=	fonts
DISTFILES=	FontPack910_chs_i486-linux.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 9 (Chinese Simplified)

DEPENDS+=	acroread9-font-share>=9.1:../../fonts/acroread9-font-share

WRKSRC=		${WRKDIR}/CHSKIT
TAR_FILE=	${WRKSRC}/LANGCHS.TAR

.include "../../fonts/acroread9-font-share/Makefile.common"
