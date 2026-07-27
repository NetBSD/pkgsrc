# $NetBSD: Makefile,v 1.4 2026/07/27 15:38:30 ryoon Exp $

DISTNAME=	zsync-0.6.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://zsync.moria.org.uk/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://zsync.moria.org.uk/
COMMENT=	Optimising file distribution program, a 1-to-many rsync
LICENSE=	artistic-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
FORCE_C_STD=	c99

# for strcasecmp(3)
CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../mk/bsd.pkg.mk"
