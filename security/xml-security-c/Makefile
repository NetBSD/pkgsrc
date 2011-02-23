# $NetBSD: Makefile,v 1.7 2011/02/23 09:02:07 adam Exp $

DISTNAME=	xml-security-c-1.6.0
CATEGORIES=	security devel
MASTER_SITES=	http://santuario.apache.org/dist/c-library/

MAINTAINER=	hasso@NetBSD.org
HOMEPAGE=	http://santuario.apache.org/
COMMENT=	XML Digital Signature specification implementation
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}"

BUILDLINK_API_DEPENDS.openssl+= openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
