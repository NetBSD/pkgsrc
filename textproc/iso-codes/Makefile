# $NetBSD: Makefile,v 1.44 2015/09/01 23:36:13 mef Exp $

DISTNAME=	iso-codes-3.61
CATEGORIES=	textproc
MASTER_SITES=	https://pkg-isocodes.alioth.debian.org/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pkg-isocodes.alioth.debian.org/
COMMENT=	List of country, language and currency names
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	iso-codes.pc.in
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

REPLACE_PYTHON=		iso2pot.py

PYTHON_FOR_BUILD_ONLY=		yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
