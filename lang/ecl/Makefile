# $NetBSD: Makefile,v 1.32 2026/09/09 20:11:30 ktnb Exp $

DISTNAME=		ecl-26.5.5
CATEGORIES=		lang
MASTER_SITES=		https://common-lisp.net/project/ecl/static/files/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		https://common-lisp.net/project/ecl/
COMMENT=		Embeddable Common Lisp
LICENSE=		gnu-lgpl-v2

USE_LANGUAGES=	c c++

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes
TEXINFO_REQD+=		5.2

CONFIGURE_ARGS+=	--enable-boehm=system --enable-gmp=system

SUBST_CLASSES+=		libdir
SUBST_STAGE.libdir=	pre-configure
SUBST_MESSAGE.libdir=	Fixing libffi layout.
SUBST_FILES.libdir=	src/c/ffi.d
SUBST_SED.libdir=	-e '/include.*<ffi/ffi.h>/s:ffi/ffi.h:ffi.h:'

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Fixing rpath variable for Darwin.
SUBST_FILES.rpath=	src/configure
SUBST_SED.rpath=	-e 's,@rpath,${PREFIX}/lib/,g'

.include "options.mk"

PLIST_SUBST=	PKGVERSION_MAJOR_MINOR=${PKGVERSION_NOREV:R} \
		PKGVERSION_MAJOR=${PKGVERSION_NOREV:R:R}

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
