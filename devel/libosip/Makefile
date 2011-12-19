# $NetBSD: Makefile,v 1.15 2011/12/19 12:56:04 schwarz Exp $
#

DISTNAME=	libosip2-3.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=osip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/osip/
COMMENT=	Implementation of SIP
LICENSE=	gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-trace
CONFIGURE_ARGS+=	--enable-md5
PKGCONFIG_OVERRIDE+=	libosip2.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
