# $NetBSD: Makefile,v 1.1.1.1 2002/04/27 09:53:43 rh Exp $

DISTNAME=	TeXmacs-1.0.0.2-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.texmacs.org
COMMENT=	GNU TeXmacs (free scientific text editor)

DEPENDS+=	autoconf>=2.13:../../devel/autoconf
DEPENDS+=	teTeX>=1.0:../../print/teTeX
DEPENDS+=	guile>=1.4:../../lang/guile

ALL_TARGET=	TEXMACS

MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

LDFLAGS+=	-Wl,-R${LOCALBASE}/libexec/${PKGNAME}/lib

pre-configure:
	cd ${WRKSRC} && autoconf;

.include "../../mk/x11.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

