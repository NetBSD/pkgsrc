# $NetBSD: Makefile,v 1.2 2003/03/22 01:03:09 wiz Exp $
#

DISTNAME=	rdiff-backup-0.10.2
CATEGORIES=	sysutils net
MASTER_SITES=	http://rdiff-backup.stanford.edu/

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://rdiff-backup.stanford.edu/
COMMENT=	remote incremental backup utility

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

.include "../../devel/librsync/buildlink2.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
