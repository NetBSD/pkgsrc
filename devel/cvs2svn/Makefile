# $NetBSD: Makefile,v 1.19 2008/01/26 09:40:56 xtraeme Exp $

DISTNAME=	cvs2svn-2.0.1
#PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://cvs2svn.tigris.org/files/documents/1462/39919/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cvs2svn.tigris.org/
COMMENT=	Converts a CVS repository to a Subversion repository

DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base

CONFLICTS+=	py*-subversion<1.0.1

PYDISTUTILSPKG=			yes
PYTHON_PATCH_SCRIPTS=		run-tests.py

# XXX cvs2svn depends on sort(1) with '-T' option. A dependency and a patch
# to resort on GNU sort from coreutils may be required.

INSTALLATION_DIRS+=	share/doc/cvs2svn

post-install:
	cd ${WRKSRC}/www && \
	${INSTALL_DATA} *.html ${PREFIX}/share/doc/cvs2svn

do-test:
	cd ${WRKSRC} && ./run-tests.py

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
