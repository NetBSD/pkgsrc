# $NetBSD: Makefile,v 1.4 2001/02/17 17:51:49 wiz Exp $
#

DISTNAME=	mpdist-3.5.2
PKGNAME=	mp-3.5.2
CATEGORIES=	print
MASTER_SITES=	http://java.sun.com/people/richb/RichApps/mp/

MAINTAINER=     kim@tac.nyc.ny.us
HOMEPAGE=	http://java.sun.com/people/richb/
COMMENT=	PostScript pretty printer

GNU_CONFIGURE=	yes

USE_X11=	yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=--disable-mptool
CONFIGURE_ARGS+=--with-prologue=${PREFIX}/share/mp

.if ${OPSYS} == "SunOS"
.else
CONFIGURE_ARGS+=--enable-bsd-print
.endif

post-install:
	${MV} ${PREFIX}/share/mpdist ${PREFIX}/share/mp
	${RM} -f ${PREFIX}/man/man1/mptool.1

.include "../../mk/bsd.pkg.mk"
