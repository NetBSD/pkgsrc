# $NetBSD: Makefile,v 1.5 2001/02/17 18:09:30 wiz Exp $

DISTNAME=		xrolodex.1.5.motif
PKGNAME=		xrolodex-1.5
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
COMMENT=		Motif/X11 rolodex application

WRKSRC=			${WRKDIR}/xrolodex.15
MAKE_ENV+=		XMLIB='-lXm'
USE_MOTIF=		yes
USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
