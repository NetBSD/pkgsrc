# $NetBSD: Makefile,v 1.9 2014/05/29 23:37:27 wiz Exp $

DISTNAME=	scrub-2.5.2
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://diskscrub.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://code.google.com/p/diskscrub/
COMMENT=	Utility to overwrite disks and scrub the data on them
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake
USE_TOOLS+=	perl # this is purely for GNU configure (X_AC_META macro)

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

.include "../../mk/bsd.pkg.mk"
