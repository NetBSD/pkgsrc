# $NetBSD: Makefile,v 1.9 2001/09/12 02:30:23 jlam Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Motif/X11 rolodex application

WRKSRC=			${WRKDIR}/xrolodex.15
MAKE_ENV+=		XMLIB="${MOTIFLIB}"
USE_IMAKE=		yes

.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
