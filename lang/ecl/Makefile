# $NetBSD: Makefile,v 1.22 2016/03/11 20:32:30 asau Exp $

DISTNAME=		ecl-16.1.2
CATEGORIES=		lang
MASTER_SITES=		https://common-lisp.net/project/ecl/files/release/$(PKGVERSION_NOREV)/
EXTRACT_SUFX=		.tgz

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		https://common-lisp.net/project/ecl/
COMMENT=		Embeddable Common Lisp
LICENSE=		gnu-lgpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-boehm=system --with-system-gmp

SUBST_CLASSES+=			fix-libffi-include
SUBST_STAGE.fix-libdir=		post-patch
SUBST_MESSAGE.fix-libdir=	Fixing libffi layout.
SUBST_FILES.fix-libdir=		src/c/ffi.d
SUBST_SED.fix-libdir=		-e '/include.*<ffi/ffi.h>/s:ffi/ffi.h:ffi.h:'

.include "options.mk"

PLIST_SUBST=	PKGVERSION_MAJOR_MINOR=${PKGVERSION_NOREV:R} \
		PKGVERSION_MAJOR=${PKGVERSION_NOREV:R:R}

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
