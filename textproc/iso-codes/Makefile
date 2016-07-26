# $NetBSD: Makefile,v 1.52 2016/07/26 13:37:28 richard Exp $

DISTNAME=	iso-codes-3.68
PKGREVISION=	1
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
REPLACE_PYTHON+=	bin/check_valid_utf8.py
REPLACE_PYTHON+=	bin/pot_from_json.py
REPLACE_PYTHON+=	bin/validate_json_data.py
REPLACE_PYTHON+=	bin/xml_from_json.py

SUBST_CLASSES+=		python3
SUBST_SED.python3+=	-e "s,python3,${PYTHONBIN},"
SUBST_FILES.python3+=	common.mk
SUBST_FILES.python3+=	iso_15924/Makefile.in
SUBST_FILES.python3+=	iso_3166-1/Makefile.in
SUBST_FILES.python3+=	iso_3166-2/Makefile.in
SUBST_FILES.python3+=	iso_3166-3/Makefile.in
SUBST_FILES.python3+=	iso_4217/Makefile.in
SUBST_FILES.python3+=	iso_639-2/Makefile.in
SUBST_FILES.python3+=	iso_639-3/Makefile.in
SUBST_FILES.python3+=	iso_639-5/Makefile.in
SUBST_STAGE.python3=	pre-configure
SUBST_MESSAGE.python3=	Fixing path to python binary.

PYTHON_FOR_BUILD_ONLY=		yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
