# $NetBSD: Makefile,v 1.2 2008/07/21 22:38:21 agc Exp $
#

DISTNAME=	scrub-2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=diskscrub/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/diskscrub
COMMENT=	Utility to overwrite disks and scrub the data on them

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl # this is purely for GNU configure

.include "../../mk/bsd.pkg.mk"
