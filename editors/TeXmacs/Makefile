# $NetBSD: Makefile,v 1.3 2002/06/16 18:50:26 wiz Exp $

DISTNAME=	TeXmacs-1.0.0.7-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.texmacs.org
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	teTeX>=1.0:../../print/teTeX
DEPENDS+=	guile>=1.4:../../lang/guile
BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf

ALL_TARGET=	TEXMACS

MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

LDFLAGS+=	-Wl,-R${LOCALBASE}/libexec/${PKGNAME}/lib

pre-configure:
	cd ${WRKSRC} && autoconf;
	${RM} ${WRKSRC}/misc/scripts/tm_axiom

.include "../../mk/x11.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

