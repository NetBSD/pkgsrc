# $NetBSD: Makefile,v 1.8 2004/04/25 09:19:19 snj Exp $
#

DISTNAME=	toshutils-991217
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ne426pd.in2home.co.uk/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.buzzard.org.uk/toshiba/
COMMENT=	NetBSD port of the Toshiba(tm) Linux Utilities

ONLY_FOR_PLATFORM= *-*-i386

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/toshutils
.for f in ac.gif battery.gif hand.gif display.html machine.html modules.html size.html space.html style.html tuxtime.html whatis.html hci.tex sci.tex toshiba.tex
	${INSTALL_MAN}	${WRKSRC}/doc/${f}	${PREFIX}/share/doc/toshutils
.endfor

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
