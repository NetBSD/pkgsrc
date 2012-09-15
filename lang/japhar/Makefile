# $NetBSD: Makefile,v 1.29 2012/09/15 10:05:19 obache Exp $
#

DISTNAME=		japhar-0.08
PKGREVISION=		7
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hungry.com/old-hungry/products/japhar/
COMMENT=		Java Virtual Machine, currently JDK 1.1.5-level

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

INFO_FILES=	# PLIST

# The japhar tar archive uses ././@LongLink GNU tar hacks
EXTRACT_USING=		nbtar

post-extract:
	${RM} -r ${WRKSRC}/lib/libffi

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
