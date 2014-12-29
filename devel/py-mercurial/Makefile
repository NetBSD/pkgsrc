# $NetBSD: Makefile,v 1.4 2014/12/29 19:56:26 wiz Exp $

DISTNAME=	mercurial-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	http://mercurial.selenic.com/release/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://mercurial.selenic.com/
COMMENT=	Fast, lightweight source control management system
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # OR newer

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
# with this dependency, two zip test cases start working
# http://bz.selenic.com/show_bug.cgi?id=4483
# http://bz.selenic.com/show_bug.cgi?id=4485
#BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

USE_TOOLS+=			gmake msgfmt

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/doc/mercurial

.include "Makefile.version"

do-test:
	cd ${WRKSRC} && make tests PYTHON=${PYTHONBIN}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/README  \
		${DESTDIR}${PREFIX}/share/doc/mercurial

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
