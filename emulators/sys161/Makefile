# $NetBSD: Makefile,v 1.5 2015/08/08 18:44:32 dholland Exp $

DISTNAME=	sys161-2.0.3
CATEGORIES=	emulators
MASTER_SITES=	http://www.eecs.harvard.edu/~dholland/os161/download/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://www.eecs.harvard.edu/~dholland/os161/\#sys161
COMMENT=	System/161 MIPS emulator
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--destdir=${DESTDIR} --prefix=${PREFIX} mipseb

.include "../../mk/bsd.pkg.mk"
