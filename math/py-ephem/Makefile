# $NetBSD: Makefile,v 1.3 2008/04/25 20:39:10 joerg Exp $
#

DISTNAME=		pyephem-3.7b
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/pyephem/ephem/}
CATEGORIES=		geography
MASTER_SITES=		http://www.rhodesmill.org/brandon/projects/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rhodesmill.org/brandon/projects/pyephem.html
COMMENT=		Scientific-grade astronomical computations for Python

# See ../../x11/xephem/Makefile.
LICENSE=		xephem-license
RESTRICTED=		Combined work is both GPL and non-Free
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PYDISTUTILSPKG=			true

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME}
	${INSTALL} ${WRKSRC}/doc/pyephem-manual.html ${PREFIX}/share/doc/${PKGNAME}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
