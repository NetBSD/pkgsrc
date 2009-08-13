# $NetBSD: Makefile,v 1.3 2009/08/13 18:17:18 asau Exp $
#

DISTNAME=		ecl-9.8.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://ecls.sourceforge.net/
COMMENT=		Embeddable Common Lisp

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-boehm=system --with-system-gmp

.include "options.mk"

PLIST_SUBST=	PKGVERSION_MAJOR_MINOR=${PKGVERSION_NOREV:R} \
		PKGVERSION_MAJOR=${PKGVERSION_NOREV:R:R}

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
