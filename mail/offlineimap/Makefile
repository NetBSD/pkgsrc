# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:34 rillig Exp $
#

DISTNAME=	offlineimap_${_OFFLINEIMAP_VER}
PKGNAME=	offlineimap-${_OFFLINEIMAP_VER}
CATEGORIES=	mail
MASTER_SITES=	http://gopher.quux.org:70/devel/offlineimap/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://gopher.quux.org:70/devel/offlineimap/
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

WRKSRC=		${WRKDIR}/offlineimap

# This is only to placate pkglint
_OFFLINEIMAP_VER=	4.0.6

PYTHON_VERSIONS_ACCEPTED=	22 23
PYDISTUTILSPKG=			yes
PYTHON_PATCH_SCRIPTS=		bin/offlineimap
PLIST_SUBST+=			PYSITELIB=${PYSITELIB:Q}

INSTALLATION_DIRS=	man/man1 share/examples/offlineimap

post-install:
.for _f_ in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${_f_} ${PREFIX}/share/examples/offlineimap/${_f_}
.endfor
	${INSTALL_MAN} ${WRKSRC}/offlineimap.1 ${PREFIX}/man/man1/offlineimap.1

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
