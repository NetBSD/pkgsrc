# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:49 jmmv Exp $
#

DISTNAME=	offlineimap_${_OFFLINEIMAP_VER}
PKGNAME=	offlineimap-${_OFFLINEIMAP_VER}
WRKSRC=		${WRKDIR}/offlineimap
CATEGORIES=	mail
MASTER_SITES=	http://gopher.quux.org:70/devel/offlineimap/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://gopher.quux.org:70/devel/offlineimap/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

USE_BUILDLINK2=	# defined

# This is only to placate pkglint
_OFFLINEIMAP_VER=	4.0.0

PYTHON_VERSIONS_ACCEPTED=	22pth 23pth
BUILDLINK_DEPENDS.python22-pth=	python22-pth>=2.2.2
PYTHON_PATCH_SCRIPTS=		bin/offlineimap
PYTHON_PATCH_SCRIPT_SED=	-e "1s;^\#!.*python.*;\#!${PYTHONBIN};"
PLIST_SUBST+=			PYSITELIB=${PYSITELIB}

do-build:
	cd ${WRKSRC}; ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC}; ${PYTHONBIN} setup.py install

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/offlineimap
.for _f_ in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${_f_} ${PREFIX}/share/examples/offlineimap/${_f_}
.endfor
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/offlineimap.1 ${PREFIX}/man/man1/offlineimap.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
