# $NetBSD: Makefile,v 1.10 2002/10/08 12:39:28 jlam Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
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
