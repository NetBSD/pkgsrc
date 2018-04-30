# $NetBSD: Makefile,v 1.18 2018/04/30 05:25:24 ryoon Exp $

DISTNAME=	xml-security-c-1.7.3
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_APACHE:=/santuario/c-library/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://santuario.apache.org/
COMMENT=	XML Digital Signature specification implementation
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}"

BUILDLINK_API_DEPENDS.openssl+= openssl>=1.1
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
