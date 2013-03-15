# $NetBSD: Makefile,v 1.7 2013/03/15 22:13:02 wiz Exp $
#

DISTNAME=	orc-0.4.17
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

.include "../../mk/bsd.pkg.mk"
