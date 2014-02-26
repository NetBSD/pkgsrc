# $NetBSD: Makefile,v 1.3 2014/02/26 04:00:57 agc Exp $

DISTNAME=		pbc-0.5.14
CATEGORIES=		security
MASTER_SITES=		http://crypto.stanford.edu/pbc/files/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://crypto.stanford.edu/pbc/
COMMENT=		Pair-based cryptographic library based on Gap Diffie Helman groups
LICENSE=		gnu-lgpl-v2

AUTO_MKDIRS=		yes

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		bison

.include "../../devel/gmp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
