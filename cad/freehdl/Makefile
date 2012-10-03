# $NetBSD: Makefile,v 1.3 2012/10/03 21:53:59 wiz Exp $
#

DISTNAME=	freehdl-0.0.7
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://seul.org/~enaroska/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freehdl.seul.org/
COMMENT=	VHDL simulator

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run pkg-config
INFO_FILES=	yes
REPLACE_PERL+=	freehdl/gvhdl.in
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../mk/bsd.pkg.mk"
