# $NetBSD: Makefile,v 1.17 1999/01/30 23:18:52 agc Exp $
#

DISTNAME=	sdr-2.5.8
CATEGORIES=	mbone tk80
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/experimental/2.5.8/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/

DEPENDS+=	tk-8.0p2:../../x11/tk80

CONFLICTS=	sdr-2.4a7mmrz

MIRROR_DISTFILE=	no
WRKSRC=		${WRKDIR}/sdr
USE_GMAKE=	yes
USE_X11BASE=	yes

_INTTYPES!=	if [ -e /usr/include/sys/inttypes.h ]; then echo "Exists"; else echo "No go"; fi

.if (${_INTTYPES} == "Exists")
EXTRA_FLAGS+= -DHAVE_SYS_INTTYPES_H
MAKE_FLAGS+=	EXTRA_FLAGS="${EXTRA_FLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
