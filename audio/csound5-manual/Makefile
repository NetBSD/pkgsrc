# $NetBSD: Makefile,v 1.1.1.1 2006/05/21 22:51:05 ben Exp $
#

DISTNAME=		Csound${CSOUND_VERSION}_manual_html
PKGNAME=		csound5-manual-${CSOUND_VERSION}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/}
EXTRACT_SUFX=		.zip

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Csound5 Reference Manual

CSOUND_VERSION=		5.01
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/html
DIST_SUBDIR=		${PKGNAME_NOREV}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/csound5
	cd ${WRKSRC} && ${PAX} -rw * ${PREFIX}/share/doc/html/csound5

.include "../../mk/bsd.pkg.mk"
