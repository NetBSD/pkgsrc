# $NetBSD: Makefile,v 1.12 1998/11/05 05:32:18 mycroft Exp $
# FreeBSD Id: Makefile,v 1.6 1997/10/15 20:35:20 fenner Exp 
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
