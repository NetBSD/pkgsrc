# $NetBSD: Makefile,v 1.7 2001/08/22 17:38:59 jlam Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Motif/X11 rolodex application

WRKSRC=			${WRKDIR}/xrolodex.15
MAKE_ENV+=		XMLIB='-lXm'
USE_IMAKE=		yes

.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
