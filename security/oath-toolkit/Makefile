# $NetBSD: Makefile,v 1.5 2012/10/23 18:16:37 asau Exp $
#

DISTNAME=	oath-toolkit-1.10.5
CATEGORIES=	security
MASTER_SITES=	http://download.savannah.gnu.org/releases/oath-toolkit/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/oath-toolkit/
COMMENT=	OATH (Open AuTHentication) Toolkit
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	liboath/liboath.pc.in

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
