# $NetBSD: Makefile,v 1.51 2023/12/29 18:24:57 adam Exp $

DISTNAME=	opensaml-3.1.0
PKGREVISION=	
PKGREVISION=	12
CATEGORIES=	security
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/${PKGVERSION_NOREV}/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.opensaml.org/
COMMENT=	Security Assertion Markup Language (SAML)
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc
USE_TOOLS+=		pkg-config

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/log4shib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../textproc/xmltooling/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
