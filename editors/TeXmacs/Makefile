# $NetBSD: Makefile,v 1.19 2003/12/24 13:02:00 jmmv Exp $

DISTNAME=	TeXmacs-1.0.1-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.texmacs.org
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX

ALL_TARGET=	TEXMACS

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=	-Wl,${RPATH_FLAG}${PREFIX}/libexec/${PKGNAME}/lib

PKG_DOCDIR=	${PREFIX}/share/doc/TeXmacs
PKG_CXXFLAGS=	-DPKG_DOCDIR=\"\\\"${PKG_DOCDIR}\\\"\"
CONFIGURE_ENV+=	PKG_CXXFLAGS="${PKG_CXXFLAGS}"
CONFIGURE_ENV+=	PKG_LDFLAGS="${LDFLAGS}"

post-extract:
	${RM} ${WRKSRC}/misc/scripts/tm_axiom
	${MV} ${WRKSRC}/misc/scripts/texmacs.in \
	      ${WRKSRC}/misc/scripts/texmacs.in.in

pre-configure:
	${SED} -e "s|@PKG_GUILE_PATH@|${GUILE14_PREFIX_DEFAULT}/bin|g" \
		< ${WRKSRC}/misc/scripts/texmacs.in.in > \
	          ${WRKSRC}/misc/scripts/texmacs.in

post-install:
	${LN} -s ${PREFIX}/share/doc/TeXmacs \
	         ${PREFIX}/share/${PKGNAME_NOREV}/doc

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
