# $NetBSD: Makefile,v 1.12 2004/01/24 13:51:14 grant Exp $
#

DISTNAME=		japhar-0.08
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.japhar.org/pub/hungry/japhar/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.japhar.org/
COMMENT=		Java Virtual Machine, currently JDK 1.1.5-level

ONLY_FOR_PLATFORM=	SunOS-*-*       # untested on NetBSD

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
USE_GCC_SHLIB=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/lib/libffi/ltconfig

INFO_FILES=	japhar.info

.include "../../mk/bsd.prefs.mk"

# The japhar tar archive uses ././@LongLink GNU tar hacks
.undef EXTRACT_USING_PAX

.include "../../mk/bsd.pkg.mk"
