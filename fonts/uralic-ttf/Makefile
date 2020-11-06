# $NetBSD: Makefile,v 1.5 2020/11/06 18:04:27 maya Exp $
#

DISTNAME=	uralic-ttf-0.0.20040603
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.peoples.org.ru/font/
DISTFILES=	BookmanUralic.zip ChanceryUralic.zip GothicUralic.zip \
		MonoUralic.zip PalladioUralic.zip RomanUralic.zip \
		SansUralic.zip SansCondUralic.zip SchoolbookUralic.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://peoples.org.ru/eng_uralic.html
COMMENT=	Font for Uralic languages with Russian-based writing systems
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
