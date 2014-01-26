# $NetBSD: Makefile,v 1.7 2014/01/26 10:28:53 wiz Exp $

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		cmake
USE_CMAKE=		yes

USE_LANGUAGES+=		c99
# Perhaps not, but cmake complains
USE_LANGUAGES+=		 c++

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	fann.pc.in

.include "../../mk/bsd.pkg.mk"
