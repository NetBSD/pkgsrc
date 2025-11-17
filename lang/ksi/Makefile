# $NetBSD: Makefile,v 1.28 2025/11/17 11:01:02 wiz Exp $

DISTNAME=		ksi-3.9.0
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ksi/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ksi.sourceforge.net/
COMMENT=		Portable, embeddable Scheme implementation written in C
LICENSE=		gnu-lgpl-v2.1

MAKE_JOBS_SAFE=		no

CPPFLAGS+=		-Dunix
GNU_CONFIGURE=		yes
USE_TOOLS+=		makeinfo
INFO_FILES=		yes
MAKE_ENV+=		GC_PREFIX=${BUILDLINK_PREFIX.boehm-gc:Q}
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/boehm-gc/buildlink3.mk"
# uses rl_event_hook() interface
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
