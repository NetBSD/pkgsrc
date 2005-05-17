# $NetBSD: Makefile,v 1.16 2005/05/17 20:56:51 jlam Exp $
#

DISTNAME=		japhar-0.08
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.japhar.org/pub/hungry/japhar/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.japhar.org/
COMMENT=		Java Virtual Machine, currently JDK 1.1.5-level

ONLY_FOR_PLATFORM=	SunOS-*-*       # untested on NetBSD

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/lib/libffi/ltconfig

INFO_FILES=	japhar.info

# The japhar tar archive uses ././@LongLink GNU tar hacks
EXTRACT_USING=		nbtar

.include "../../mk/bsd.pkg.mk"
