# $NetBSD: Makefile,v 1.6 1998/06/22 12:52:32 agc Exp $
# $FreeBSD Id: Makefile,v 1.15 1998/02/07 22:59:16 hoek Exp
#

DISTNAME=	ical-2.2
CATEGORIES=	misc
MASTER_SITES=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/icalbins/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	tk-8.0p2:../../x11/tk80

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
