# $NetBSD: Makefile,v 1.12 2012/07/05 14:51:47 asau Exp $
#

DISTNAME=		ecl-12.2.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://ecls.sourceforge.net/
COMMENT=		Embeddable Common Lisp
LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

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
