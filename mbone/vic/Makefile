# $NetBSD: Makefile,v 1.7 1998/06/22 12:47:36 agc Exp $
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

post-install:
	strip ${PREFIX}/bin/vic
	strip ${PREFIX}/bin/histtolut

.include "../../mk/bsd.pkg.mk"
