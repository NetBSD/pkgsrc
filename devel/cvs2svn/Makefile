# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:26 tv Exp $

DISTNAME=	cvs2svn-1.0.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cvs2svn.tigris.org/files/documents/1462/15996/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://cvs2svn.tigris.org/
COMMENT=	Converts a CVS repository to a Subversion repository

DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base

CONFLICTS+=	py*-subversion<1.0.1

PYDISTUTILSPKG=			yes
USE_BUILDLINK3=			YES
PYTHON_PATCH_SCRIPTS=		run-tests.py

# XXX cvs2svn depends on sort(1) with '-T' option. A dependency and a patch
# to resort on GNU sort from coreutils may be required.

INSTALLATION_DIRS+=	share/doc/html/cvs2svn

post-install:
	for f in ${WRKSRC}/www/*.html; do				\
		${INSTALL_DATA} $${f} ${PREFIX}/share/doc/html/cvs2svn;	\
	done

do-test:
	cd ${WRKSRC}; ./run-tests.py

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
