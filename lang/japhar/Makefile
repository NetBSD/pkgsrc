# $NetBSD: Makefile,v 1.23 2006/06/06 15:40:15 joerg Exp $
#

DISTNAME=		japhar-0.08
PKGREVISION=		4
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

post-extract:
	${RM} -r ${WRKSRC}/lib/libffi

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
