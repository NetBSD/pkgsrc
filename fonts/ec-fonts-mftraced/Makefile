# $NetBSD: Makefile,v 1.20 2009/07/22 09:01:27 wiz Exp $
#

DISTNAME=		ec-fonts-mftraced-1.0.8
PKGREVISION=		6
CATEGORIES=		fonts
MASTER_SITES=		http://lilypond.org/download/fonts/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lilypond.org/web/
COMMENT=		EC PostScript Type1 fonts with TFMs for TeX

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX:Q}
TEX_FONTMAPS=		ec-mftrace.map

.include "../../fonts/mftrace/buildlink3.mk"
.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
