# $NetBSD: Makefile,v 1.2 2005/12/26 23:39:31 schmonz Exp $
#

DISTNAME=	chtfont
CATEGORIES=	fonts

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 7 (Chinese Traditional)

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

DEPENDS+=	acroread7-font-share-7.0:../../fonts/acroread7-font-share

WRKSRC=		${WRKDIR}/CHTKIT
TAR_FILE=	${WRKSRC}/LANGCHT.TAR

.include "../../fonts/acroread7-font-share/Makefile.common"
