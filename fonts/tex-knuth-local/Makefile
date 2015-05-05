# $NetBSD: Makefile,v 1.2 2015/05/05 18:13:30 wiz Exp $

DISTNAME=	knuth-local
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	33147

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/knuth-local
COMMENT=	Knuth's local information
#LICENSE=	knuth

DEPENDS+=	web2c-[0-9]*:../../print/web2c

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/texmf-dist/mft/knuth-local
	${INSTALL_DATA} ${WRKSRC}/mft/knuth-local/e.mft \
		${DESTDIR}${PREFIX}/share/texmf-dist/mft/knuth-local/e.mft

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
