# $NetBSD: Makefile,v 1.5 2003/08/14 12:08:00 abs Exp $
#

DISTNAME=	rdiff-backup-0.12.3
CATEGORIES=	sysutils net
MASTER_SITES=	http://rdiff-backup.stanford.edu/

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://rdiff-backup.stanford.edu/
COMMENT=	Remote incremental backup utility

PYTHON_VERSION_REQD=	22
USE_BUILDLINK2=		yes

post-patch:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		< ${WRKSRC}/setup.py > ${WRKSRC}/local_setup.py

do-build:
	cd ${WRKSRC}; ${PYTHONBIN} local_setup.py build

do-install:
	cd ${WRKSRC}; ${PYTHONBIN} local_setup.py install \
		--prefix=${PREFIX} --skip-build

BUILDLINK_DEPENDS.librsync=	librsync>=0.9.6

.include "../../devel/librsync/buildlink2.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
