# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:38 jlam Exp $
#

DISTNAME=		ec-fonts-mftraced-1.0.8
PKGREVISION=		4
CATEGORIES=		fonts
MASTER_SITES=		http://lilypond.org/download/fonts/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lilypond.org/
COMMENT=		EC PostScript Type1 fonts with TFMs for TeX

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile
MAKE_ENV+=		PKG_TEXMFPREFIX=${PKG_TEXMFPREFIX:Q}
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX:Q}

.include "../../fonts/mftrace/buildlink3.mk"
.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
