# $NetBSD: Makefile,v 1.2 2024/02/27 19:13:44 schmonz Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		py-vmailmgr-${VERSION}
CATEGORIES=		mail python

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (Python bindings)
LICENSE=		gnu-gpl-v2

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
