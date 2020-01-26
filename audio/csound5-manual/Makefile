# $NetBSD: Makefile,v 1.11 2020/01/26 17:30:41 rillig Exp $
#

DISTNAME=		Csound${CSOUND_VERSION}_manual_html
PKGNAME=		csound5-manual-${CSOUND_VERSION}
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csound/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.csounds.com/
COMMENT=		Csound5 Reference Manual
LICENSE=		gnu-fdl-v1.2

CSOUND_VERSION=		5.19
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/html
DIST_SUBDIR=		${PKGNAME_NOREV}
USE_TOOLS+=		pax

INSTALLATION_DIRS+=	share/doc/csound5

do-install:
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${PREFIX}/share/doc/csound5

.include "../../mk/bsd.pkg.mk"
