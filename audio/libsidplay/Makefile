# $NetBSD: Makefile,v 1.15 2004/02/17 23:52:45 jmmv Exp $
#

DISTNAME=	libsidplay-1.36.57
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Sidplay Library

CONFLICTS=	sidplay-1.36.*

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
USE_GCC_SHLIB=		yes

.include "../../mk/bsd.pkg.mk"
