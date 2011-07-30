# $NetBSD: Makefile,v 1.8.4.1 2011/07/30 05:40:46 sbd Exp $

DISTNAME=	xml-security-c-1.6.1
CATEGORIES=	security devel
MASTER_SITES=	http://apache.dataphone.se/santuario/c-library/ \
		http://www.apache.org/dist//santuario/c-library/


MAINTAINER=	pkgsrc-users@NetBSD.org
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
