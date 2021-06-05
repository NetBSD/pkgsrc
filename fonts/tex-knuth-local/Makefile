# $NetBSD: Makefile,v 1.6 2021/06/05 07:22:34 markd Exp $

DISTNAME=	knuth-local
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	57963

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/knuth-local
COMMENT=	Knuth's local information
LICENSE=	public-domain

DEPENDS+=	web2c-[0-9]*:../../print/web2c

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/texmf-dist/mft/knuth-local
	${INSTALL_DATA} ${WRKSRC}/mft/knuth-local/e.mft \
		${DESTDIR}${PREFIX}/share/texmf-dist/mft/knuth-local/e.mft

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
