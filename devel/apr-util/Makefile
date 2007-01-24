# $NetBSD: Makefile,v 1.1.1.1 2007/01/24 19:37:20 epg Exp $
#

DISTNAME=	apr-util-1.2.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=apr/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime utilities

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	apr-util.pc.in

CONFIGURE_ARGS+= \
		--with-apr=${BUILDLINK_PREFIX.apr}/bin/apr-1-config \
		--with-expat=${BUILDLINK_PREFIX.expat} \
		--without-gdbm

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
