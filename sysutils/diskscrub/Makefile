# $NetBSD: Makefile,v 1.7 2013/12/15 19:44:39 joerg Exp $
#

DISTNAME=	scrub-2.5.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://diskscrub.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://code.google.com/p/diskscrub/
COMMENT=	Utility to overwrite disks and scrub the data on them
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl # this is purely for GNU configure (X_AC_META macro)

.include "../../mk/bsd.pkg.mk"
