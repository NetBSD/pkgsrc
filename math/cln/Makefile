# $NetBSD: Makefile,v 1.21 2011/11/20 05:40:27 sbd Exp $

DISTNAME=	cln-1.3.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ginac.de/CLN/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ginac.de/CLN/
COMMENT=	CLN Class Library for Numbers
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	cln.pc.in
INFO_FILES=		yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
