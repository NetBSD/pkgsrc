# $NetBSD: Makefile,v 1.74 2024/05/29 16:32:20 adam Exp $

DISTNAME=	rudiments-1.4.2
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rudiments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rudiments.sourceforge.net/
COMMENT=	C++ class library for client/server/daemon applications
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-apache2
CONFIGURE_ARGS+=	--disable-werror
PTHREAD_AUTO_VARS=	yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
