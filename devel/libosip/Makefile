# $NetBSD: Makefile,v 1.5 2005/07/13 04:50:46 grant Exp $
#

DISTNAME=	libosip2-2.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=osip/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/osip/
COMMENT=	Implementation of SIP

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-trace
CONFIGURE_ARGS+=	--enable-md5
PKGCONFIG_OVERRIDE+=	libosip2.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
