# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 14:43:55 agc Exp $
#

DISTNAME=	gpsim-0.20.7
CATEGORIES=	emulators
MASTER_SITES=	http://www.dattalo.com/gnupic/

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	http://www.dattalo.com/gnupic/gpsim
COMMENT=	PIC emulator with X interface

DEPENDS+=	gtk+-1.*:../../x11/gtk
DEPENDS+=	gtk+extra-*:../../x11/gtk+extra
DEPENDS+=	eXdbm-*:../../devel/eXdbm
DEPENDS+=	readline>=2.0:../../devel/readline
DEPENDS+=	popt-*:../../devel/popt

CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	YES
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS}" LDFLAGS+="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-exdbm=${PREFIX}

USE_GMAKE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
