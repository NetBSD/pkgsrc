# $NetBSD: Makefile,v 1.35 2009/02/11 22:59:49 abs Exp $

DISTNAME=	rconfig-0.47
CATEGORIES=	sysutils
MASTER_SITES=	http://rconfig.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/rconfig/
COMMENT=	Manage configurations for many machines via rdist trees

DEPENDS+=	fping-[0-9]*:../../net/fping
DEPENDS+=	freerdist-[0-9]*:../../net/rdist6
DEPENDS+=	shmux-[0-9]*:../../sysutils/shmux

PKG_DESTDIR_SUPPORT=    user-destdir

USE_TOOLS+=	perl:run

.include "../../mk/bsd.pkg.mk"
