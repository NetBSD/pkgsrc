# $NetBSD: Makefile,v 1.1.1.1 2000/02/23 20:20:45 jlam Exp $

DISTNAME=	slib2c7
PKGNAME=	slib-2c7
CATEGORIES=	devel
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/ \
		${MASTER_SITE_GNU:=jacal/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html

BUILD_DEPENDS+=	${LOCALBASE}/bin/unzip:../../archivers/unzip

WRKSRC=		${WRKDIR}/slib
EXTRACT_CMD=	${LOCALBASE}/bin/unzip -uLa \
			${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

NO_CONFIGURE=	yes
NO_BUILD=	yes

SLIBDIR=	share/slib
DOCDIR=		share/doc/slib

INFO_FILES=	slib.info

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${SLIBDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.scm *.init ${PREFIX}/${SLIBDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README FAQ ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/slib.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
