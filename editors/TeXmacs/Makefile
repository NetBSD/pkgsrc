# $NetBSD: Makefile,v 1.5 2002/09/06 11:59:38 wiz Exp $

DISTNAME=	TeXmacs-1.0.0.15-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.texmacs.org
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX
BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

ALL_TARGET=	TEXMACS

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
MANCOMPRESSED=	yes

LDFLAGS+=	-Wl,-R${LOCALBASE}/libexec/${PKGNAME}/lib

pre-configure:
	( cd ${WRKSRC} && autoconf )
	${RM} ${WRKSRC}/misc/scripts/tm_axiom

.include "../../lang/guile/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
