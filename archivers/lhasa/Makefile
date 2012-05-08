# $NetBSD: Makefile,v 1.2 2012/05/08 06:13:27 wiz Exp $
#

DISTNAME=	lhasa-0.0.5
CATEGORIES=	archivers
MASTER_SITES=	http://cloud.github.com/downloads/fragglet/lhasa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fragglet.github.com/lhasa/
COMMENT=	Freely licensed lha archiving tool (for .lzh and .lha files)
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	check

CONFLICTS=	lha-[0-9]*

.include "../../mk/bsd.pkg.mk"
