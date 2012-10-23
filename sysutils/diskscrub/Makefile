# $NetBSD: Makefile,v 1.4 2012/10/23 19:50:58 asau Exp $
#

DISTNAME=	scrub-2.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=diskscrub/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/diskscrub
COMMENT=	Utility to overwrite disks and scrub the data on them

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl # this is purely for GNU configure

.include "../../mk/bsd.pkg.mk"
