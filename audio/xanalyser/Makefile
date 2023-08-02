# $NetBSD: Makefile,v 1.25 2023/08/02 19:20:17 nia Exp $
#

DISTNAME=	xanalyser-1.32
CATEGORIES=	audio
MASTER_SITES=	http://arvin.schnell-web.net/xanalyser/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arvin.schnell-web.net/xanalyser/
COMMENT=	Frequency spectrum analyser for X
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

# Fails with C++14 default language
FORCE_CXX_STD=		c++03

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
