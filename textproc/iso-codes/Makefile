# $NetBSD: Makefile,v 1.12 2007/08/01 12:07:50 obache Exp $
#

DISTNAME=	iso-codes-1.3
CATEGORIES=	textproc
MASTER_SITES=	ftp://pkg-isocodes.alioth.debian.org/pub/pkg-isocodes/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/pkg-isocodes/
COMMENT=	List of country, language and currency names

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

PKGCONFIG_OVERRIDE=	iso-codes.pc.in

REPLACE_PYTHON=		*.py */*.py

DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

PYTHON_FOR_BUILD_ONLY=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
