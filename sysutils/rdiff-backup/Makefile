# $NetBSD: Makefile,v 1.23 2006/03/04 21:30:42 jlam Exp $
#

DISTNAME=	rdiff-backup-1.0.1
PKGREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/rdiff-backup/
COMMENT=	Remote incremental backup utility

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	setup.py
SUBST_SED.path=		-e "s|%%LOCALBASE%%|${LOCALBASE}|g"
SUBST_MESSAGE.path=	"Fixing paths."

BUILDLINK_DEPENDS.librsync+=	librsync>=0.9.6

.include "../../devel/librsync/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
