# $NetBSD: Makefile,v 1.26 2020/03/20 11:57:55 nia Exp $

DISTNAME=		ksi-3.9.0
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ksi/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ksi.sourceforge.net/
COMMENT=		Portable, embeddable Scheme implementation written in C

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
