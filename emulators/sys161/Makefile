# $NetBSD: Makefile,v 1.6 2016/01/18 05:17:56 dholland Exp $

DISTNAME=	sys161-2.0.6
CATEGORIES=	emulators
MASTER_SITES=	http://os161.eecs.harvard.edu/download/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://os161.eecs.harvard.edu/\#sys161
COMMENT=	System/161 MIPS emulator
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--destdir=${DESTDIR} --prefix=${PREFIX} mipseb

.include "../../mk/bsd.pkg.mk"
