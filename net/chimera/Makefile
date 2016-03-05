# $NetBSD: Makefile,v 1.5 2016/03/05 11:29:02 jperkin Exp $

DISTNAME=	chimera-1.20
PKGREVISION=	1
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

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
