# $NetBSD: Makefile,v 1.14 2004/01/20 12:21:02 agc Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
PKGREVISION=		1
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Motif/X11 rolodex application

WRKSRC=			${WRKDIR}/xrolodex.15
USE_BUILDLINK2=		# defined
USE_IMAKE=		# defined

MAKE_ENV+=		XMLIB="${MOTIFLIB}"

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
