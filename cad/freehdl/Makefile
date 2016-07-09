# $NetBSD: Makefile,v 1.8 2016/07/09 06:37:51 wiz Exp $
#

DISTNAME=	freehdl-0.0.7
PKGREVISION=	5
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

.include "../../mk/bsd.pkg.mk"
