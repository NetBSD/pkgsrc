# $NetBSD: Makefile,v 1.31 2005/07/16 01:19:20 jlam Exp $

DISTNAME=	rconfig-0.42
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mono.org/abs/tools/rconfig/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.mono.org/abs/tools/rconfig/
COMMENT=	Manage configurations for many machines via rdist trees

DEPENDS+=	fping-[0-9]*:../../net/fping
DEPENDS+=	freerdist-[0-9]*:../../net/rdist6
DEPENDS+=	shmux-[0-9]*:../../sysutils/shmux

USE_TOOLS+=	perl:run

.include "../../mk/bsd.pkg.mk"
