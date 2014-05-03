# $NetBSD: Makefile,v 1.59 2014/05/03 19:40:22 adam Exp $

DISTNAME=	libtasn1-3.5
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNU:=libtasn1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libtasn1/
COMMENT=	ASN.1 structure parser library
LICENSE=	gnu-fdl-v1.3 AND gnu-lgpl-v2.1 AND gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
INFO_FILES=		yes

CONFIGURE_ARGS+=	--with-packager="pkgsrc"
CONFIGURE_ARGS+=	--with-packager-version="${PKGVERSION}"
CONFIGURE_ARGS+=	--with-packager-bug-reports="http://gnats.NetBSD.org/"

.include "../../mk/bsd.prefs.mk"

# Mac OS X has no prototype for getopt_long and no declaration for
# struct option, so ignore getopt_long() even though the test succeeds.
.if ${OPSYS} == "Darwin"
CONFIGURE_ENV+=		ac_cv_func_getopt_long=no
CFLAGS+=	-fno-common
.endif

.include "../../mk/bsd.pkg.mk"
