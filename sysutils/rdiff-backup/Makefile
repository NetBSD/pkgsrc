# $NetBSD: Makefile,v 1.68 2026/10/23 13:05:13 adam Exp $

DISTNAME=	rdiff_backup-2.2.7
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	sysutils net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdiff-backup/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://rdiff-backup.net/
COMMENT=	Remote incremental backup utility
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

SUBST_CLASSES+=		manpath
SUBST_MESSAGE.manpath=	Fixing path to manpages.
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e "s|share/man|${PKGMANDIR}|"

.include "../../lang/python/wheel.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
