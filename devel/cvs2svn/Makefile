# $NetBSD: Makefile,v 1.45 2023/12/22 17:44:47 zafer Exp $

DISTNAME=	cvs2svn-2.3.0
PKGREVISION=	7
CATEGORIES=	devel scm
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mhagger/cvs2svn
COMMENT=	Converts a CVS repository to a Subversion repository

DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base

CONFLICTS+=	py*-subversion<1.0.1

REPLACE_PYTHON=	run-tests.py cvs2svn_rcsparse/run-tests.py \
			cvs2svn_rcsparse/parse_rcs_file.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.3.0
#USE_TOOLS+=	gtar
#EXTRACT_USING=	gtar

# XXX cvs2svn depends on sort(1) with '-T' option. A dependency and a patch
# to resort on GNU sort from coreutils may be required.

INSTALLATION_DIRS+=	share/doc/cvs2svn
INSTALLATION_DIRS+=	share/examples/cvs2svn

post-install:
	cd ${WRKSRC}/www && \
	${INSTALL_DATA} *.html ${DESTDIR}${PREFIX}/share/doc/cvs2svn
	cd ${WRKSRC} && \
	${INSTALL_DATA} cvs2svn-example.options ${DESTDIR}${PREFIX}/share/examples/cvs2svn

do-test:
	cd ${WRKSRC} && ./run-tests.py

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
