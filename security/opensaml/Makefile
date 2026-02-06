# $NetBSD: Makefile,v 1.68 2026/02/06 10:05:49 wiz Exp $

DISTNAME=	opensaml-3.3.1
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensaml.org/
COMMENT=	Security Assertion Markup Language (SAML)
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-libs}
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
