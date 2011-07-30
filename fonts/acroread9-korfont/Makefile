# $NetBSD: Makefile,v 1.1.1.1 2011/07/30 07:38:36 ryoon Exp $
#

DISTNAME=	korfont
CATEGORIES=	fonts
DISTFILES=	FontPack910_kor_i486-linux.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 9 (Korean)

DEPENDS+=	acroread9-font-share>=9.1:../../fonts/acroread9-font-share

WRKSRC=		${WRKDIR}/KORKIT
TAR_FILE=	${WRKSRC}/LANGKOR.TAR

.include "../../fonts/acroread9-font-share/Makefile.common"
