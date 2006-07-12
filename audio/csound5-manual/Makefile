# $NetBSD: Makefile,v 1.3 2006/07/12 17:09:50 rillig Exp $
#

DISTNAME=		Csound${CSOUND_VERSION}_manual_html
PKGNAME=		csound5-manual-${CSOUND_VERSION}
PKGREVISION=		2
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
EXTRACT_OPTS_ZIP=	-aqo

INSTALLATION_DIRS+=	share/doc/csound5

do-install:
	cd ${WRKSRC} && ${PAX} -rw * ${PREFIX}/share/doc/csound5

.include "../../mk/bsd.pkg.mk"
