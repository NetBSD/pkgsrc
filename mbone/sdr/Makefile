# $NetBSD: Makefile,v 1.11 1998/10/02 06:47:29 hubertf Exp $
# FreeBSD Id: Makefile,v 1.6 1997/10/15 20:35:20 fenner Exp 
#

DISTNAME=	sdr.V2.4a7n
PKGNAME=	sdr-2.4a7mmrz
CATEGORIES=	mbone tk80
MASTER_SITES=	http://north.east.isi.edu/sdr/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://north.east.isi.edu/sdr/

DEPENDS+=	tk-8.0p2:../../x11/tk80

MIRROR_DISTFILE=	no
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes
USE_X11=	yes

_INTTYPES!=	if [ -e /usr/include/sys/inttypes.h ]; then echo "Exists"; else echo "No go"; fi

.if (${_INTTYPES} == "Exists")
CFLAGS+= -DHAVE_SYS_INTTYPES_H
.endif

.include "../../mk/bsd.pkg.mk"
