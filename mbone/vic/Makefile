# $NetBSD: Makefile,v 1.10 1999/04/01 13:38:44 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/11 03:54:53 fenner Exp
#

DISTNAME=	vic-2.8
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.8.tar.gz

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www-nrg.ee.lbl.gov/vic/

DEPENDS+=	tk-8.0.5:../../x11/tk80

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

post-install:
	strip ${PREFIX}/bin/vic
	strip ${PREFIX}/bin/histtolut

.include "../../mk/bsd.pkg.mk"
