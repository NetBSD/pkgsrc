# $NetBSD: Makefile,v 1.10 2009/06/08 13:19:20 tron Exp $

DISTNAME=	apr-util-1.3.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=apr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime utilities

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apr=${BUILDLINK_PREFIX.apr}/bin/apr-1-config
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--without-gdbm
PKGCONFIG_OVERRIDE+=	apr-util.pc.in

MAKE_ENV+=	WRAPPER_DIR=${WRAPPER_DIR:Q}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.apr+=	apr>=1.3.0
.include "../../devel/apr/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
