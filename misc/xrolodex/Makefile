# $NetBSD: Makefile,v 1.11 2003/03/02 20:21:37 jschauma Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
PKGREVISIO=		1
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Motif/X11 rolodex application

USE_BUILDLINK2=		# defined
USE_IMAKE=		# defined

WRKSRC=			${WRKDIR}/xrolodex.15
MAKE_ENV+=		XMLIB="${MOTIFLIB}"

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
