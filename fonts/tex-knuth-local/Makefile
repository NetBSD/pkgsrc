# $NetBSD: Makefile,v 1.4 2019/12/06 19:30:09 markd Exp $

DISTNAME=	knuth-local
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	38627

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/knuth-local
COMMENT=	Knuth's local information
#LICENSE=	knuth

DEPENDS+=	web2c-[0-9]*:../../print/web2c

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/texmf-dist/mft/knuth-local
	${INSTALL_DATA} ${WRKSRC}/mft/knuth-local/e.mft \
		${DESTDIR}${PREFIX}/share/texmf-dist/mft/knuth-local/e.mft

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
