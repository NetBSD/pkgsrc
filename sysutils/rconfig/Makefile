# $NetBSD: Makefile,v 1.24 2004/07/16 12:51:26 abs Exp $

DISTNAME=	rconfig-0.34
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mono.org/abs/tools/rconfig/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.mono.org/abs/tools/rconfig/
COMMENT=	Manage configurations for many machines via rdist trees

DEPENDS+=	fping-[0-9]*:../../net/fping
DEPENDS+=	freerdist-[0-9]*:../../net/rdist6

USE_PERL5=	# defined

.include "../../mk/bsd.pkg.mk"
