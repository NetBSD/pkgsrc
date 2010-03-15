# $NetBSD: Makefile,v 1.1.1.1 2010/03/15 19:40:44 pettai Exp $
#

DISTNAME=	opensaml-2.3
CATEGORIES=	security
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/opensaml/cpp/2.3/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.opensaml.org/
COMMENT=	Security Assertion Markup Language (SAML)
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/log4shib/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../textproc/xmltooling/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
