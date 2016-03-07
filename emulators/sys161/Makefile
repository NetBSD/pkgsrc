# $NetBSD: Makefile,v 1.7 2016/03/07 05:53:29 dholland Exp $

DISTNAME=	sys161-2.0.8
CATEGORIES=	emulators
MASTER_SITES=	http://os161.eecs.harvard.edu/download/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://os161.eecs.harvard.edu/\#sys161
COMMENT=	System/161 MIPS emulator
LICENSE=	modified-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--destdir=${DESTDIR} --prefix=${PREFIX} mipseb

.include "../../mk/bsd.pkg.mk"
