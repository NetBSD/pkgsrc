# $NetBSD: Makefile,v 1.19 2006/02/16 16:33:28 reed Exp $
#

DISTNAME=		japhar-0.08
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_BACKUP}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.hungry.com/old-hungry/products/japhar/
COMMENT=		Java Virtual Machine, currently JDK 1.1.5-level

ONLY_FOR_PLATFORM=	SunOS-*-*       # untested on NetBSD

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/lib/libffi/ltconfig

INFO_FILES=	japhar.info

# The japhar tar archive uses ././@LongLink GNU tar hacks
EXTRACT_USING=		nbtar

.include "../../mk/bsd.pkg.mk"
