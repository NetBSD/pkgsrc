# $NetBSD: Makefile,v 1.1.1.1 2010/07/18 12:22:25 drochner Exp $
#

DISTNAME=	orc-0.4.6
CATEGORIES=	devel
MASTER_SITES=	http://code.entropywave.com/download/orc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.entropywave.com/projects/orc/
COMMENT=	Compiler for vector operations
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	orc.pc.in
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
