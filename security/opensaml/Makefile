# $NetBSD: Makefile,v 1.4 2011/02/23 09:11:09 adam Exp $

DISTNAME=	opensaml-2.4.1
CATEGORIES=	security
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/opensaml/cpp/${PKGVERSION_NOREV}/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.opensaml.org/
COMMENT=	Security Assertion Markup Language (SAML)
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/log4shib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../textproc/xmltooling/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
