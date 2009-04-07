# $NetBSD: Makefile,v 1.28 2009/04/07 10:30:20 drochner Exp $
#

DISTNAME=	iso-codes-3.7
CATEGORIES=	textproc
MASTER_SITES=	ftp://pkg-isocodes.alioth.debian.org/pub/pkg-isocodes/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alioth.debian.org/projects/pkg-isocodes/
COMMENT=	List of country, language and currency names

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

PKGCONFIG_OVERRIDE=	iso-codes.pc.in

REPLACE_PYTHON=		*.py */*.py

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

PYTHON_FOR_BUILD_ONLY=		yes

INSTALLATION_DIRS=	share/doc/iso-codes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/iso-codes
	${INSTALL_DATA} ${WRKSRC}/TODO ${DESTDIR}${PREFIX}/share/doc/iso-codes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
