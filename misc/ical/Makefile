# $NetBSD: Makefile,v 1.9 1999/04/26 18:56:14 garbled Exp $
# $FreeBSD Id: Makefile,v 1.15 1998/02/07 22:59:16 hoek Exp
#

DISTNAME=	ical-2.2
CATEGORIES=	misc
MASTER_SITES=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/icalbins/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/

DEPENDS+=	tk-8.0.5:../../x11/tk80

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tclconfig=${PREFIX}/lib/tcl8.0 \
		--with-tclhdir=${PREFIX}/include/tcl8.0 \
		--with-tclsh=${PREFIX}/bin/tclsh8.0 \
		--with-tkconfig=${PREFIX}/lib/tk8.0 \
		--with-tkhdir=${PREFIX}/include/tk8.0

post-install:
	@strip ${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
