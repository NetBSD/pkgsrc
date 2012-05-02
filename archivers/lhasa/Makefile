# $NetBSD: Makefile,v 1.1.1.1 2012/05/02 12:19:43 wiz Exp $
#

DISTNAME=	lhasa-0.0.4
CATEGORIES=	archivers
MASTER_SITES=	http://cloud.github.com/downloads/fragglet/lhasa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fragglet.github.com/lhasa/
COMMENT=	Freely licensed lha archiving tool (for .lzh and .lha files)
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
# tests currently only succeed in timezone Europe/London
TEST_TARGET=	check

CONFLICTS=	lha-[0-9]*

.include "../../mk/bsd.pkg.mk"
