# $NetBSD: Makefile,v 1.20 2012/10/02 20:11:44 asau Exp $

DISTNAME=		ksi-3.9.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ksi/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ksi.sourceforge.net/
COMMENT=		Portable, embeddable Scheme implementation written in C

MAKE_JOBS_SAFE=		no

CPPFLAGS+=		-Dunix
GNU_CONFIGURE=		yes
USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST
MAKE_ENV+=		GC_PREFIX=${BUILDLINK_PREFIX.boehm-gc:Q}
USE_GNU_READLINE=	# uses rl_event_hook() interface
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
