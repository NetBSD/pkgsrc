# $NetBSD: Makefile,v 1.5 2004/04/18 05:05:43 snj Exp $
#

DISTNAME=	offlineimap_${_OFFLINEIMAP_VER}
PKGNAME=	offlineimap-${_OFFLINEIMAP_VER}
CATEGORIES=	mail
MASTER_SITES=	http://gopher.quux.org:70/devel/offlineimap/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://gopher.quux.org:70/devel/offlineimap/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

WRKSRC=		${WRKDIR}/offlineimap
USE_BUILDLINK3=	yes

# This is only to placate pkglint
_OFFLINEIMAP_VER=	4.0.0

PYTHON_VERSIONS_ACCEPTED=	22pth 23pth
PYDISTUTILSPKG=			yes
PYTHON_PATCH_SCRIPTS=		bin/offlineimap
PLIST_SUBST+=			PYSITELIB=${PYSITELIB}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/offlineimap
.for _f_ in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${_f_} ${PREFIX}/share/examples/offlineimap/${_f_}
.endfor
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/offlineimap.1 ${PREFIX}/man/man1/offlineimap.1

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
