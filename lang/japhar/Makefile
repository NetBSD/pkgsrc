# $NetBSD: Makefile,v 1.22 2006/06/04 13:52:57 joerg Exp $
#

DISTNAME=		japhar-0.08
PKGREVISION=		3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hungry.com/old-hungry/products/japhar/
COMMENT=		Java Virtual Machine, currently JDK 1.1.5-level

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/lib/libffi/ltconfig

INFO_FILES=	# PLIST

# The japhar tar archive uses ././@LongLink GNU tar hacks
EXTRACT_USING=		nbtar

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
