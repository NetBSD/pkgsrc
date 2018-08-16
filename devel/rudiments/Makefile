# $NetBSD: Makefile,v 1.50 2018/08/16 18:54:29 adam Exp $
#

DISTNAME=		rudiments-1.0.2
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rudiments/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rudiments.sourceforge.net/
COMMENT=		C++ class library for client/server/daemon applications
LICENSE=		gnu-lgpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
PTHREAD_AUTO_VARS=	YES

BUILDLINK_TRANSFORM+=	rm:-Wno-long-double

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-Wno-error=unused-private-field
CWRAPPERS_APPEND.cxx+=	-Wno-error=unused-private-field
# Avoid deprecation errors on Darwin for GSS.framework
CWRAPPERS_APPEND.cxx+=	-Wno-error=deprecated-declarations
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
