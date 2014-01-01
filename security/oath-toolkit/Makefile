# $NetBSD: Makefile,v 1.10 2014/01/01 11:52:33 wiz Exp $
#

DISTNAME=	oath-toolkit-2.4.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://download.savannah.gnu.org/releases/oath-toolkit/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/oath-toolkit/
COMMENT=	OATH (Open AuTHentication) Toolkit
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

USE_TOOLS+=	autoconf automake m4

DEPENDS+=       automake>=1.14:../../devel/automake

PKGCONFIG_OVERRIDE+=	liboath/liboath.pc.in

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
