# $NetBSD: Makefile,v 1.16 2004/10/03 00:13:00 tv Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
PKGREVISION=		2
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Motif/X11 rolodex application

WRKSRC=			${WRKDIR}/xrolodex.15
USE_BUILDLINK3=		yes
USE_IMAKE=		# defined

MAKE_ENV+=		XMLIB="${MOTIFLIB}"

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
