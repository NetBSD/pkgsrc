# $NetBSD: Makefile,v 1.4 2014/12/10 05:46:00 dholland Exp $

DISTNAME=	sys161-1.99.10
CATEGORIES=	emulators
MASTER_SITES=	http://www.eecs.harvard.edu/~dholland/os161/download/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://www.eecs.harvard.edu/~dholland/os161/\#sys161
COMMENT=	System/161 MIPS emulator
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX} mipseb

.include "../../mk/bsd.pkg.mk"
