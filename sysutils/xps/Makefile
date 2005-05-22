# $NetBSD: Makefile,v 1.29 2005/05/22 20:08:34 jlam Exp $

DISTNAME=	xps-4.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif-pstree/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://motif-pstree.sourceforge.net/
COMMENT=	Displays the Unix process list as a hierarchical tree

USE_TOOLS+=		gmake
USE_PERL5=		build
GNU_CONFIGURE=		yes

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
