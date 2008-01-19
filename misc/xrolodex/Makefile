# $NetBSD: Makefile,v 1.22 2008/01/19 09:16:25 wiz Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
PKGREVISION=		4
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Motif/X11 rolodex application

WRKSRC=			${WRKDIR}/xrolodex.15
USE_IMAKE=		yes

MAKE_ENV+=		XMLIB=${MOTIFLIB:Q}

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
