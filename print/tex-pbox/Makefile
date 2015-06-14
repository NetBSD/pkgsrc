# $NetBSD: Makefile,v 1.1 2015/06/14 14:20:11 joerg Exp $

DISTNAME=		pbox
PKGNAME=		tex-${DISTNAME}-1.2
EXTRACT_SUFX=		.tar.xz
TEXLIVE_USE_CTAN=	yes

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		A variable-width pbox
LICENSE=		gnu-gpl-v3

INSTALLATION_DIRS=	share/texmf-dist/tex/latex/pbox

do-install:
	${INSTALL_DATA} ${WRKSRC}/tex/latex/pbox/pbox.sty \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/pbox

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
