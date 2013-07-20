# $NetBSD: Makefile,v 1.39 2013/07/20 05:10:42 richard Exp $

DISTNAME=	pgadmin3-1.16.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL:=pgadmin3/release/v${PKGVERSION_NOREV}/src/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.pgadmin.org/
COMMENT=	Graphical PostgreSQL client and administration tool
LICENSE=	postgresql-license

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		automake autoreconf gmake msgfmt
GNU_CONFIGURE=		yes

PKG_OPTIONS_VAR=        PKG_OPTIONS.pgadmin3
PKG_SUPPORTED_OPTIONS=	pgadmin-db-designer doc
PKG_SUGGESTED_OPTIONS=	pgadmin-db-designer

.include "../../mk/bsd.options.mk"

PLIST_VARS=	doc

###
### Database Designer support
###
.if !empty(PKG_OPTIONS:Mpgadmin-db-designer)
CONFIGURE_ARGS+=        --enable-databasedesigner
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=	yes
PYTHON_FOR_BUILD_ONLY=yes
.include "../../lang/python/pyversion.mk"
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx>=1.0:../../textproc/py-sphinx
.else
CONFIGURE_ENV+=		ac_cv_path_SPHINX_BUILD=
.endif

CONFIGURE_ARGS+=	--with-wx=${BUILDLINK_PREFIX.wxGTK28}
CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-libxslt=${BUILDLINK_PREFIX.libxslt}

pre-configure:
	cd ${WRKSRC} && autoreconf -vfi

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/wxGTK28-contrib/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
