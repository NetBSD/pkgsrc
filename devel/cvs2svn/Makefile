# $NetBSD: Makefile,v 1.3 2004/05/12 19:24:18 seb Exp $

DISTNAME=	cvs2svn-0.${CVS2SVN_REVISION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://cvs2svn.tigris.org/
COMMENT=	Converts a CVS repository to a Subversion repository

DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base

CONFLICTS+=	py*-subversion<1.0.1

CVS2SVN_REVISION=		947
NO_BUILD=			# defined
PY_PATCHPLIST=			# defined
USE_BUILDLINK3=			YES
PYTHON_PATCH_SCRIPTS=		cvs2svn.py verify-cvs2svn.py run-tests.py

INSTALLATION_DIRS+=	bin share/doc/cvs2svn ${PYSITELIB}/rcsparse

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cvs2svn
	${INSTALL_SCRIPT} ${WRKSRC}/cvs2svn.py ${PREFIX}/bin/cvs2svn
	${INSTALL_SCRIPT} ${WRKSRC}/verify-cvs2svn.py			\
	  ${PREFIX}/bin/verify-cvs2svn
	for f in ${WRKSRC}/rcsparse/*.py; do				\
		${INSTALL_DATA} $$f ${PREFIX}/${PYSITELIB}/rcsparse;	\
	done

do-test:
	cd ${WRKSRC}; ./run-tests.py

# Generate the distfile out of cvs2svn repository as
# cvs2svn is not yet packaged by its authors.
gen-distfile:
	${MKDIR} ${WRKDIR}
	svn export -r${CVS2SVN_REVISION} http://svn.collab.net/repos/cvs2svn/trunk/ ${WRKDIR}/cvs2svn-0.${CVS2SVN_REVISION}
	cd ${WRKDIR} && ${PAX} -w cvs2svn-0.${CVS2SVN_REVISION} | ${GZIP_CMD} > ${DISTDIR}/cvs2svn-0.${CVS2SVN_REVISION}.tar.gz

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
