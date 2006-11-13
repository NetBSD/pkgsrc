# $NetBSD: Makefile,v 1.2 2006/11/13 22:49:51 gdt Exp $
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
PYTHON_VERSIONS_ACCEPTED=	23 24

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME}
	${INSTALL} ${WRKSRC}/doc/pyephem-manual.html ${PREFIX}/share/doc/${PKGNAME}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
