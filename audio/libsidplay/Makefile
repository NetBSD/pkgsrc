# $NetBSD: Makefile,v 1.12 2003/10/29 16:57:32 gavan Exp $
#

DISTNAME=	libsidplay-1.36.57
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Sidplay Library

CONFLICTS=	sidplay-1.36.*

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_GCC_SHLIB=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
