# $NetBSD: Makefile,v 1.38 2012/10/25 06:55:57 asau Exp $

DISTNAME=	iso-codes-3.11.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://pkg-isocodes.alioth.debian.org/pub/pkg-isocodes/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/pkg-isocodes/
COMMENT=	List of country, language and currency names
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

PKGCONFIG_OVERRIDE=	iso-codes.pc.in

REPLACE_PYTHON=		*.py */*.py

PYTHON_FOR_BUILD_ONLY=		yes

INSTALLATION_DIRS=	share/doc/iso-codes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/iso-codes
	${INSTALL_DATA} ${WRKSRC}/TODO ${DESTDIR}${PREFIX}/share/doc/iso-codes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
