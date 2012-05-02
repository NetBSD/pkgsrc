# $NetBSD: Makefile,v 1.1.1.1 2012/05/02 04:48:04 agc Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir
AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"
