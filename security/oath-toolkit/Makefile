# $NetBSD: Makefile,v 1.23 2022/04/18 19:12:00 adam Exp $

DISTNAME=	oath-toolkit-2.4.1
PKGREVISION=	8
CATEGORIES=	security
MASTER_SITES=	http://download.savannah.gnu.org/releases/oath-toolkit/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/oath-toolkit/
COMMENT=	OATH (Open AuTHentication) Toolkit
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

USE_TOOLS+=	autoconf automake m4 autoreconf

BUILD_DEPENDS+=	automake>=1.14:../../devel/automake
TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc

PKGCONFIG_OVERRIDE+=	liboath/liboath.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
