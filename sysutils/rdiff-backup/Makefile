# $NetBSD: Makefile,v 1.27 2008/04/25 20:39:12 joerg Exp $
#

DISTNAME=	rdiff-backup-1.0.5
CATEGORIES=	sysutils net
MASTER_SITES=	http://savannah.nongnu.org/download/rdiff-backup/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/rdiff-backup/
COMMENT=	Remote incremental backup utility

PYDISTUTILSPKG=		yes

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	setup.py
SUBST_SED.path=		-e "s|%%LOCALBASE%%|${LOCALBASE}|g"
SUBST_MESSAGE.path=	Fixing paths.

BUILDLINK_API_DEPENDS.librsync+=	librsync>=0.9.6

.include "../../devel/librsync/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
