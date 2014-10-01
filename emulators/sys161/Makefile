# $NetBSD: Makefile,v 1.3 2014/10/01 08:11:29 dholland Exp $

DISTNAME=	sys161-1.99.09
CATEGORIES=	emulators
MASTER_SITES=	http://www.eecs.harvard.edu/~dholland/os161/download/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://www.eecs.harvard.edu/~dholland/os161/\#sys161
COMMENT=	System/161 MIPS emulator
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX} mipseb

.include "../../mk/bsd.pkg.mk"
