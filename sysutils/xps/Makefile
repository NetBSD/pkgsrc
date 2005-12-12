# $NetBSD: Makefile,v 1.31 2005/12/12 21:36:55 joerg Exp $

DISTNAME=	xps-4.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif-pstree/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://motif-pstree.sourceforge.net/
COMMENT=	Displays the Unix process list as a hierarchical tree

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
