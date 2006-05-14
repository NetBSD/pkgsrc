# $NetBSD: Makefile,v 1.11 2006/05/14 20:46:37 minskim Exp $
#

PKGNAME=	python23-nth-2.3.5
PKGREVISION=	6

CONFLICTS+=	python-[0-9]*

CONFIGURE_ARGS+=        --without-threads

PY_VER_SUFFIX=	2n3

DISTINFO_FILE=		${.CURDIR}/../../lang/python23/distinfo
PATCHDIR=		${.CURDIR}/../../lang/python23/patches

SUBST_CLASSES+=		version
SUBST_FILES.version=	configure Include/patchlevel.h setup.py
SUBST_SED.version+=	-e 's,VERSION=2\.3,VERSION=2n3,g'
SUBST_SED.version+=	-e 's,\(PY_VERSION.*\)2\.3,\12n3,g'
SUBST_SED.version+=	-e 's,pydoc2\.3,pydoc2n3,g'
SUBST_STAGE.version=	pre-configure

.include "../../lang/python23/Makefile.common"
