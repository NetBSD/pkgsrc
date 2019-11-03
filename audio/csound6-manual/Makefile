# $NetBSD: Makefile,v 1.15 2019/11/03 08:27:07 rillig Exp $

DISTNAME=		Csound${CSOUND_VERSION}_manual_html
PKGNAME=		csound6-manual-${CSOUND_VERSION}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=csound/}
GITHUB_PROJECT=		manual
GITHUB_TYPE=		release
GITHUB_RELEASE=		${CSOUND_VERSION}
EXTRACT_SUFX=		.zip

MAINTAINER=		mrg@eterna.com.au
HOMEPAGE=		http://www.csounds.com/
COMMENT=		Csound6 Reference Manual
LICENSE=		gnu-fdl-v1.2

CSOUND_VERSION=		6.13.0
WRKSRC=			${WRKDIR}/html
USE_TOOLS+=		gmake pax
EXTRACT_USING=		bsdtar
NO_BUILD=		yes

DOCDIR=			share/doc/csound6
INSTALLATION_DIRS+=	${DOCDIR}

do-install:
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
