# $NetBSD: Makefile,v 1.6 1998/04/22 14:22:45 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/11 03:54:53 fenner Exp
#

DISTNAME=	vic-2.8
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.8.tar.gz

MAINTAINER=	is@netbsd.org

DEPENDS+=	tk-8.0p2:../../x11/tk80

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		vic.1

post-install:
	strip ${PREFIX}/bin/vic
	strip ${PREFIX}/bin/histtolut

.include "../../mk/bsd.pkg.mk"
