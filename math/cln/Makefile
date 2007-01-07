# $NetBSD: Makefile,v 1.16 2007/01/07 09:54:52 wiz Exp $

DISTNAME=	cln-1.1.13
CATEGORIES=	math
MASTER_SITES=	http://www.ginac.de/CLN/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ginac.de/CLN/
COMMENT=	CLN Class Library for Numbers

USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	cln.pc.in
INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
