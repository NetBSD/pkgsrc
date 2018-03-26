# $NetBSD: Makefile,v 1.19.2.1 2018/03/26 19:44:33 spz Exp $

DISTNAME=	mercurial-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	https://www.mercurial-scm.org/release/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/
COMMENT=	Fast, lightweight source control management system
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # OR newer

# with this dependency, two zip test cases start working
# https://bz.mercurial-scm.org/show_bug.cgi?id=4483
# https://bz.mercurial-scm.org/show_bug.cgi?id=4485
BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

USE_TOOLS+=			gmake msgfmt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/doc/mercurial

.include "Makefile.version"

# Known test failures:
# test-status-color.t:
# https://bz.mercurial-scm.org/show_bug.cgi?id=5698
do-test:
	cd ${WRKSRC} && make tests PYTHON=${PYTHONBIN} TESTFLAGS=${_MAKE_JOBS:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/README.rst  \
		${DESTDIR}${PREFIX}/share/doc/mercurial

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
