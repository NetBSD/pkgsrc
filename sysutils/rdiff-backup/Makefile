# $NetBSD: Makefile,v 1.13 2004/10/03 00:18:16 tv Exp $
#

DISTNAME=	rdiff-backup-0.12.7
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://rdiff-backup.stanford.edu/

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://rdiff-backup.stanford.edu/
COMMENT=	Remote incremental backup utility

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 22 22pth 23 23pth
USE_BUILDLINK3=		yes

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	setup.py
SUBST_SED.path=		-e "s|%%LOCALBASE%%|${LOCALBASE}|g"
SUBST_MESSAGE.path=	"Fixing paths."

BUILDLINK_DEPENDS.librsync=	librsync>=0.9.6

.include "../../devel/librsync/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
