# $NetBSD: Makefile,v 1.6 2010/12/17 07:36:12 obache Exp $

DISTNAME=		xml-security-c-1.5.1
PKGREVISION=		3
CATEGORIES=		security devel
MASTER_SITES=		http://santuario.apache.org/dist/c-library/

MAINTAINER=		hasso@NetBSD.org
HOMEPAGE=		http://santuario.apache.org/c/index.html
COMMENT=		XML Digital Signature specification implementation
LICENSE=		apache-2.0

PKG_DESTDIR_SUPPORT=    user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.openssl+= openssl>=0.9.7

CONFIGURE_ENV+=		XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}"

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xalan-c/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
