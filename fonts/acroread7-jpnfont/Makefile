# $NetBSD: Makefile,v 1.4 2008/09/06 20:50:02 wiz Exp $
#

DISTNAME=	jpnfont
PKGREVISION=	1
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 7 (Japanese)

DEPENDS+=	acroread7-font-share>=7.0nb1:../../fonts/acroread7-font-share

WRKSRC=		${WRKDIR}/JPNKIT
TAR_FILE=	${WRKSRC}/LANGJPN.TAR

.include "../../fonts/acroread7-font-share/Makefile.common"
