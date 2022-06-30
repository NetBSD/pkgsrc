# $NetBSD: Makefile,v 1.4 2022/06/30 11:18:46 nia Exp $

DISTNAME=	print-plist-python-0.0
PKGREVISION=	3
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Test escaping in PRINT_PLIST_AWK
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
AUTO_MKDIRS=	yes

# When interpreted as a regular expression, the version number "3.7"
# matches the filename "share/emul3270". Therefore only that version works.
PYTHON_VERSIONS_ACCEPTABLE=	37

pre-build:
	${TOUCH} ${WRKDIR}/setup.py

post-build:
	${ECHO} "content" >${WRKDIR}/file

post-install:
	${INSTALL_DATA} ${WRKSRC}/file ${DESTDIR}${PREFIX}/share/emul3270
	${INSTALL_DATA} ${WRKSRC}/file ${DESTDIR}${PREFIX}/share/file-${PYVERSSUFFIX}.txt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
