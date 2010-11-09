# $NetBSD: Makefile,v 1.1.1.1 2010/11/09 03:33:28 agc Exp $

DISTNAME=		pbc-0.5.10
CATEGORIES=		security
MASTER_SITES=		http://crypto.stanford.edu/pbc/files/

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://crypto.stanford.edu/pbc/
COMMENT=		Pair-based cryptographic library based on Gap Diffie Helman groups
LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
AUTO_MKDIRS=		yes

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/gmp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
