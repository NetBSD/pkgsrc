# $NetBSD: Makefile,v 1.9 2018/08/22 09:43:00 wiz Exp $
#

DISTNAME=	freehdl-0.0.7
PKGREVISION=	6
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
