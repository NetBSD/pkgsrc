# $NetBSD: Makefile,v 1.7 2003/06/02 01:19:01 jschauma Exp $
#

DISTNAME=		japhar-0.08
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.japhar.org/pub/hungry/japhar/source/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.japhar.org/
COMMENT=		Java Virtual Machine, currently JDK 1.1.5-level

ONLY_FOR_PLATFORM=	SunOS-*-*       # untested on NetBSD

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/lib/libffi/ltconfig

.include "../../mk/bsd.prefs.mk"

# The japhar tar archive uses ././@LongLink GNU tar hacks
.undef EXTRACT_USING_PAX

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
