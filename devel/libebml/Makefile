# $NetBSD: Makefile,v 1.2 2004/01/22 08:24:30 grant Exp $
#

DISTNAME=	libebml-0.6.3
CATEGORIES=	devel
MASTER_SITES=	http://matroska.free.fr/downloads/libebml/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matroska.sourceforge.net/
COMMENT=	Librarys for the EBML (Extensible Binary Meta Language) format

BUILD_DIRS=		${WRKSRC}/make/linux
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
