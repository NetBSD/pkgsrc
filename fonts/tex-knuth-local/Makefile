# $NetBSD: Makefile,v 1.1 2015/04/26 02:31:13 markd Exp $

DISTNAME=	knuth-local
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	33147

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Knuths local information

DEPENDS+=	web2c-[0-9]*:../../print/web2c

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/texmf-dist/mft/knuth-local
	${INSTALL_DATA} ${WRKSRC}/mft/knuth-local/e.mft \
		${DESTDIR}${PREFIX}/share/texmf-dist/mft/knuth-local/e.mft

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
