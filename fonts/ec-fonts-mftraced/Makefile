# $NetBSD: Makefile,v 1.8 2005/11/13 05:30:10 minskim Exp $
#

DISTNAME=		ec-fonts-mftraced-1.0.8
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES=		http://lilypond.org/download/fonts/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://lilypond.org/
COMMENT=		EC PostScript Type1 fonts with TFMs for TeX

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile
MAKE_ENV+=		PKG_TEXMFPREFIX=${PKG_TEXMFPREFIX}
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX}

.include "../../fonts/mftrace/buildlink3.mk"
.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
