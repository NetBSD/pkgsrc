# $NetBSD: Makefile,v 1.30 2023/10/24 22:10:53 wiz Exp $

DISTNAME=	oath-toolkit-2.6.9
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://download.savannah.gnu.org/releases/oath-toolkit/

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/oath-toolkit/
COMMENT=	OATH (Open AuTHentication) Toolkit
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

USE_TOOLS+=	autoconf automake m4 autoreconf perl

TOOL_DEPENDS+=	automake>=1.14:../../devel/automake
TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc

PKGCONFIG_OVERRIDE+=	liboath/liboath.pc.in

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
