# $NetBSD: Makefile,v 1.1.1.1 2010/01/22 17:14:33 drochner Exp $
#

DISTNAME=	freehdl-0.0.7
CATEGORIES=	cad
MASTER_SITES=	http://seul.org/~enaroska/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freehdl.seul.org/
COMMENT=	VHDL simulator

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run
INFO_FILES=	yes
REPLACE_PERL+=	freehdl/gvhdl.in
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../mk/bsd.pkg.mk"
