# $NetBSD: Makefile,v 1.10 2000/08/30 22:15:44 tron Exp $
# $FreeBSD Id: Makefile,v 1.15 1998/02/07 22:59:16 hoek Exp
#

DISTNAME=	ical-2.2
CATEGORIES=	misc
MASTER_SITES=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/icalbins/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclsh=${PREFIX}/bin/tclsh \
		--with-tkconfig=${PREFIX}/lib

post-install:
	@strip ${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
