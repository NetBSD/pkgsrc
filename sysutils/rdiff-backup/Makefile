# $NetBSD: Makefile,v 1.66 2025/05/02 07:02:07 adam Exp $

DISTNAME=	rdiff-backup-2.2.6
CATEGORIES=	sysutils net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdiff-backup/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://rdiff-backup.net/
COMMENT=	Remote incremental backup utility
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

SUBST_CLASSES+=		manpath
SUBST_MESSAGE.manpath=	Fixing path to manpages.
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	setup.py
SUBST_SED.manpath=	-e "s|share/man|${PKGMANDIR}|"

.include "../../lang/python/wheel.mk"
.include "../../net/librsync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
