# $NetBSD: Makefile,v 1.3 2006/04/07 03:55:22 minskim Exp $
#

DISTNAME=	passivetex
PKGNAME=	tex-${DISTNAME}-1.24
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.tei-c.org/Software/passivetex/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org/Software/passivetex/
COMMENT=	TeX macros for formatting objects

DEPENDS+=	tex-xmltex>=1.9:../../textproc/tex-xmltex

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_DIRS+=	texmf-1.0

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/passivetex
.for f in dummyels.sty fotex.xmt fotex.sty mlnames.sty \
	  nomulticol.sty ucharacters.sty unicode.sty
	${INSTALL_DATA} ${WRKSRC}/${f} ${PKG_LOCALTEXMFPREFIX}/tex/passivetex
.endfor

.include "../../mk/bsd.pkg.mk"
