# $NetBSD: Makefile,v 1.9 2015/03/11 22:30:42 tnn Exp $

DISTNAME=	orc-0.4.18
CATEGORIES=	devel
MASTER_SITES=	http://code.entropywave.com/download/orc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.entropywave.com/projects/orc/
COMMENT=	Compiler for vector operations
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake

PKGCONFIG_OVERRIDE+=	orc.pc.in
TEST_TARGET=	check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
