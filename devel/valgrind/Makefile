# $NetBSD: Makefile,v 1.1.1.1 2005/07/21 19:44:30 jschauma Exp $
#

DISTNAME=		valgrind-2.4.0
CATEGORIES=		devel
MASTER_SITES=		http://valgrind.org/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://valgrind.org/downloads/
COMMENT=		Debugging and profiling tools

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORMS=	Linux-*-*

USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
