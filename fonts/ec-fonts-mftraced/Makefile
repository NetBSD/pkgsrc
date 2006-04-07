# $NetBSD: Makefile,v 1.14 2006/04/07 05:10:39 minskim Exp $
#

DISTNAME=		ec-fonts-mftraced-1.0.8
PKGREVISION=		5
CATEGORIES=		fonts
MASTER_SITES=		http://lilypond.org/download/fonts/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lilypond.org/
COMMENT=		EC PostScript Type1 fonts with TFMs for TeX

USE_DIRS+=		texmf-1.1
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX:Q}
TEX_FONTMAPS=		ec-mftrace.map

.include "../../fonts/mftrace/buildlink3.mk"
.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
