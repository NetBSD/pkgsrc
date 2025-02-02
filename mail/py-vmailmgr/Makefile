# $NetBSD: Makefile,v 1.3 2025/02/02 20:28:40 schmonz Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-vmailmgr-${VERSION}
CATEGORIES=		mail python

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (Python bindings)
LICENSE=		gnu-gpl-v2

CONFLICTS+=		py-vmailmgr-[0-9]*

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHONBIN=${PYTHONBIN:Q}

BUILD_DIRS=		python/vmailmgr
INSTALL_DIRS=		python/vmailmgr

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

SUBST_CLASSES+=		pyversion
SUBST_STAGE.pyversion=	pre-configure
SUBST_FILES.pyversion=	configure.ac python/vmailmgr/Makefile.am
SUBST_VARS.pyversion=	PYTHONBIN

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
