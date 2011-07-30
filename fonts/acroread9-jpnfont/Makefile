# $NetBSD: Makefile,v 1.1.1.1 2011/07/30 07:37:29 ryoon Exp $
#

DISTNAME=	jpnfont
CATEGORIES=	fonts
DISTFILES=	FontPack910_jpn_i486-linux.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 9 (Japanese)

DEPENDS+=	acroread9-font-share>=9.1:../../fonts/acroread9-font-share

WRKSRC=		${WRKDIR}/JPNKIT
TAR_FILE=	${WRKSRC}/LANGJPN.TAR

.include "../../fonts/acroread9-font-share/Makefile.common"
