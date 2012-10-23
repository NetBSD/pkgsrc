# $NetBSD: Makefile,v 1.2 2012/10/23 18:16:33 asau Exp $

DISTNAME=		pbc-0.5.10
CATEGORIES=		security
MASTER_SITES=		http://crypto.stanford.edu/pbc/files/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://crypto.stanford.edu/pbc/
COMMENT=		Pair-based cryptographic library based on Gap Diffie Helman groups
LICENSE=		gnu-lgpl-v2

AUTO_MKDIRS=		yes

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/gmp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
