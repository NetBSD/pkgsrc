# $NetBSD: Makefile,v 1.67 2023/01/31 18:44:01 wiz Exp $

DISTNAME=	apr-util-1.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_APACHE:=apr/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://apr.apache.org/
COMMENT=	Apache Portable Runtime utilities
LICENSE=	apache-2.0

# bug in 1.6.2 distfile
WRKSRC=			${WRKDIR}/apr-util-1.6.2-rc3

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apr=${BUILDLINK_PREFIX.apr}/bin/apr-1-config
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--without-gdbm
CONFIGURE_ARGS+=	--without-odbc
CONFIGURE_ARGS+=	--without-sqlite2
PKGCONFIG_OVERRIDE+=	apr-util.pc.in

# Too many differences between configure test and actual usage.
CONFIGURE_ENV.SunOS+=	apu_cv_memset_s=no

# just a list of exported symbols for a library that also starts with shebang
CHECK_INTERPRETER_SKIP=	lib/aprutil.exp

MAKE_ENV+=	WRAPPER_DIR=${WRAPPER_DIR}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.apr+=	apr>=1.5.0
.include "../../devel/apr/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
