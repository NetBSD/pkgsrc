# $NetBSD: Makefile,v 1.4 2003/05/02 11:56:30 wiz Exp $
#

DISTNAME=	toshutils-991217
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ne426pd.in2home.co.uk/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.buzzard.org.uk/toshiba/
COMMENT=	NetBSD port of the Toshiba(tm) Linux Utilities

DEPENDS+=	gtk+>=1.2.10nb4:../../x11/gtk

ONLY_FOR_PLATFORM= *-*-i386
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/toshutils
.for f in ac.gif battery.gif hand.gif display.html machine.html modules.html size.html space.html style.html tuxtime.html whatis.html hci.tex sci.tex toshiba.tex
	${INSTALL_MAN}	${WRKSRC}/doc/${f}	${PREFIX}/share/doc/toshutils
.endfor

.include "../../mk/bsd.pkg.mk"
