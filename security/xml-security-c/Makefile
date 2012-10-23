# $NetBSD: Makefile,v 1.10 2012/10/23 18:17:01 asau Exp $

DISTNAME=	xml-security-c-1.6.1
CATEGORIES=	security devel
MASTER_SITES=	http://apache.dataphone.se/santuario/c-library/ \
		http://www.apache.org/dist//santuario/c-library/


MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://santuario.apache.org/
COMMENT=	XML Digital Signature specification implementation
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}"

BUILDLINK_API_DEPENDS.openssl+= openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
