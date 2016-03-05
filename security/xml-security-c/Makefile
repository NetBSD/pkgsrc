# $NetBSD: Makefile,v 1.15 2016/03/05 11:27:55 jperkin Exp $

DISTNAME=	xml-security-c-1.7.2
PKGREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_APACHE:=/santuario/c-library/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://santuario.apache.org/
COMMENT=	XML Digital Signature specification implementation
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}"

BUILDLINK_API_DEPENDS.openssl+= openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
