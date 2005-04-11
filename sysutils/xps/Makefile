# $NetBSD: Makefile,v 1.28 2005/04/11 21:47:31 tv Exp $

DISTNAME=	xps-4.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif-pstree/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://motif-pstree.sourceforge.net/
COMMENT=	Displays the Unix process list as a hierarchical tree

USE_GNU_TOOLS+=		make
USE_PERL5=		build
GNU_CONFIGURE=		yes

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
