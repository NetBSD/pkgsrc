# $NetBSD: Makefile,v 1.9 2002/09/03 15:31:11 mycroft Exp $
#

DISTNAME=	libsidplay-1.36.56
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/
COMMENT=	Sidplay Library

CONFLICTS=	sidplay-1.36.*

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

.include "../../mk/bsd.pkg.mk"
