# $NetBSD: Makefile,v 1.3 2011/04/18 20:07:31 he Exp $
#

DISTNAME=	orc-0.4.11
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://code.entropywave.com/download/orc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.entropywave.com/projects/orc/
COMMENT=	Compiler for vector operations
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake

PKGCONFIG_OVERRIDE+=	orc.pc.in
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
