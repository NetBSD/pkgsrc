# $NetBSD: Makefile,v 1.10 2002/12/21 17:05:08 jmmv Exp $

DISTNAME=	TeXmacs-1.0.1-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.texmacs.org
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX

ALL_TARGET=	TEXMACS

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-Wl,-R${PREFIX}/libexec/${PKGNAME}/lib

PKG_DOCDIR=	${PREFIX}/share/doc/TeXmacs
PKG_CXXFLAGS=	-DPKG_DOCDIR=\"\\\"${PKG_DOCDIR}\\\"\"
CONFIGURE_ENV+=	PKG_CXXFLAGS="${PKG_CXXFLAGS}"
CONFIGURE_ENV+=	PKG_LDFLAGS="${LDFLAGS}"

pre-configure:
	${RM} ${WRKSRC}/misc/scripts/tm_axiom

post-install:
	${LN} -s ${PREFIX}/share/doc/TeXmacs ${PREFIX}/share/${PKGNAME}/doc

.include "../../lang/guile/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
