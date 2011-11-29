# $NetBSD: Makefile,v 1.36 2011/11/29 18:31:26 hans Exp $

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

USE_TOOLS+=	perl:run pod2man pod2html

.include "../../mk/bsd.pkg.mk"
