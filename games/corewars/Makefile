# $NetBSD: Makefile,v 1.26 2026/09/02 19:02:07 wiz Exp $

DISTNAME=	corewars-0.9.13
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/corewars/
#HOMEPAGE=	http://sal.math.ualberta.ca/
COMMENT=	Programs on a virtual machine, fighting each other
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		autoconf automake autoreconf bison flex gmake pkg-config
GNU_CONFIGURE=		yes

CFLAGS+=	-Wno-implicit-function-declaration

# random build failures with -j12
MAKE_JOBS_SAFE=	no

# problem with 'bool'
FORCE_C_STD=	c99

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
