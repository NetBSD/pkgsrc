# $NetBSD: Makefile,v 1.3 2012/10/03 21:57:37 wiz Exp $
#

DISTNAME=	scrub-2.0
PKGREVISION=	1
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
