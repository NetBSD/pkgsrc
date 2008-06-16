# $NetBSD: Makefile,v 1.4 2008/06/16 14:48:28 reed Exp $
#

DISTNAME=	passivetex
PKGNAME=	tex-${DISTNAME}-1.24
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.tei-c.org.uk/Software/passivetex/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org.uk/Software/passivetex/
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
