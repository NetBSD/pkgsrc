# $NetBSD: Makefile,v 1.3 2013/12/10 14:04:31 jperkin Exp $

DISTNAME=	chimera-1.20
CATEGORIES=	net
MASTER_SITES=	http://www.cs.ucsb.edu/~ravenben/chimera/download/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://pdos.csail.mit.edu/chord/
COMMENT=	Distributed Hash Table implementation
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/chimera
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

AUTO_MKDIRS=		yes

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
