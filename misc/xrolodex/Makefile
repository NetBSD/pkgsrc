# $NetBSD: Makefile,v 1.12 2003/03/29 12:41:52 jmmv Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
PKGREVISIO=		1
WRKSRC=			${WRKDIR}/xrolodex.15
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Motif/X11 rolodex application

USE_BUILDLINK2=		# defined
USE_IMAKE=		# defined

MAKE_ENV+=		XMLIB="${MOTIFLIB}"

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
