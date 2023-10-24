# $NetBSD: Makefile,v 1.25 2023/10/24 22:11:01 wiz Exp $

DISTNAME=	xml-security-c-2.0.4
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_APACHE:=/santuario/c-library/}

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
