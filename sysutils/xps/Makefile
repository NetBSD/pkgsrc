# $NetBSD: Makefile,v 1.33 2006/03/04 21:30:44 jlam Exp $

DISTNAME=	xps-4.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif-pstree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://motif-pstree.sourceforge.net/
COMMENT=	Displays the Unix process list as a hierarchical tree

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
