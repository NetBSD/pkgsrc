# $NetBSD: Makefile,v 1.8 2003/09/29 02:00:45 lukem Exp $
#

DISTNAME=	rdiff-backup-0.12.5
CATEGORIES=	sysutils net
MASTER_SITES=	http://rdiff-backup.stanford.edu/

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://rdiff-backup.stanford.edu/
COMMENT=	Remote incremental backup utility

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 22 22pth 23 23pth
USE_BUILDLINK2=		yes

post-patch:
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		< ${WRKSRC}/setup.py > ${WRKSRC}/setup.py.tmp && \
		${MV} ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

BUILDLINK_DEPENDS.librsync=	librsync>=0.9.6

.include "../../devel/librsync/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
