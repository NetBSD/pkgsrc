# $NetBSD: Makefile,v 1.19 2005/07/14 13:52:13 wiz Exp $
#

DISTNAME=	rdiff-backup-0.12.7
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/rdiff-backup/
COMMENT=	Remote incremental backup utility

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22

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
