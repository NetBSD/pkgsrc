# $NetBSD: Makefile,v 1.27 2004/09/23 11:36:16 abs Exp $

DISTNAME=	rconfig-0.37
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mono.org/abs/tools/rconfig/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.mono.org/abs/tools/rconfig/
COMMENT=	Manage configurations for many machines via rdist trees

DEPENDS+=	fping-[0-9]*:../../net/fping
DEPENDS+=	freerdist-[0-9]*:../../net/rdist6
DEPENDS+=	shmux-[0-9]*:../../sysutils/shmux

USE_PERL5=	# defined

.include "../../mk/bsd.pkg.mk"
