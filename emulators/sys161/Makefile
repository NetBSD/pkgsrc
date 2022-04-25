# $NetBSD: Makefile,v 1.8 2022/04/25 10:41:08 tnn Exp $

DISTNAME=	sys161-2.0.8
CATEGORIES=	emulators
MASTER_SITES=	http://os161.eecs.harvard.edu/download/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://os161.eecs.harvard.edu/\#sys161
COMMENT=	System/161 MIPS emulator
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--destdir=${DESTDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	mipseb

.include "../../mk/bsd.pkg.mk"
