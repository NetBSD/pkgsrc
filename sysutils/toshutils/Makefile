# $NetBSD: Makefile,v 1.1.1.1 1999/12/20 03:05:14 hubertf Exp $
#

DISTNAME=	toshutils-991217
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ne426pd.in2home.co.uk/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.buzzard.org.uk/toshiba/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/toshutils
.for f in ac.gif battery.gif hand.gif display.html machine.html modules.html size.html space.html style.html tuxtime.html whatis.html hci.tex sci.tex toshiba.tex
	${INSTALL_MAN}	${WRKSRC}/doc/${f}	${PREFIX}/share/doc/toshutils
.endfor

.include "../../mk/bsd.pkg.mk"
