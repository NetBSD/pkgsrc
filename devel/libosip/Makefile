# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:30 tv Exp $
#

DISTNAME=	libosip2-2.0.9
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=osip/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fsf.org/software/osip/osip.html
COMMENT=	Implementation of SIP

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-trace
CONFIGURE_ARGS+=	--enable-md5

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
