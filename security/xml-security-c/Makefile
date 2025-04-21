# $NetBSD: Makefile,v 1.26 2025/04/21 21:10:48 perseant Exp $

DISTNAME=	xml-security-c-3.0.0
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://shibboleth.net/downloads/xml-security-c/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://santuario.apache.org/
COMMENT=	XML Digital Signature specification implementation
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}"

do-test:
	${WRKSRC}/xsec/xsec-xtest

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
