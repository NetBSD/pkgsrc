# $NetBSD: Makefile,v 1.9 2019/11/03 10:39:10 rillig Exp $

PKGREVISION=		1

.include "Makefile.common"

COMMENT=		Fast Artificial Neural Network

LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		cmake
USE_CMAKE=		yes

USE_LANGUAGES+=	c99
# Perhaps not, but cmake complains
USE_LANGUAGES+=	c++

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	fann.pc.in

.include "../../mk/bsd.pkg.mk"
