# $NetBSD: Makefile,v 1.13 1998/11/05 06:35:24 mycroft Exp $
#

DISTNAME=	sdr-2.5.8
CATEGORIES=	mbone tk80
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/2.5.8/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://north.east.isi.edu/sdr/

DEPENDS+=	tk-8.0p2:../../x11/tk80

CONFLICTS=	sdr-2.4a7mmrz

MIRROR_DISTFILE=	no
WRKSRC=		${WRKDIR}/sdr
USE_GMAKE=	yes
USE_X11=	yes

_INTTYPES!=	if [ -e /usr/include/sys/inttypes.h ]; then echo "Exists"; else echo "No go"; fi

.if (${_INTTYPES} == "Exists")
CFLAGS+= -DHAVE_SYS_INTTYPES_H
.endif

.include "../../mk/bsd.pkg.mk"
