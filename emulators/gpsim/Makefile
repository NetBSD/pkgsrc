# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:02 jlam Exp $
#

DISTNAME=	gpsim-0.20.7
CATEGORIES=	emulators
MASTER_SITES=	http://www.dattalo.com/gnupic/

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	http://www.dattalo.com/gnupic/gpsim
COMMENT=	PIC emulator with X interface

DEPENDS+=	gtk+-1.*:../../x11/gtk
DEPENDS+=	gtk+extra-[0-9]*:../../x11/gtk+extra
DEPENDS+=	eXdbm-[0-9]*:../../devel/eXdbm
DEPENDS+=	readline>=2.0:../../devel/readline
DEPENDS+=	popt-[0-9]*:../../devel/popt

CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-exdbm=${PREFIX}

USE_GMAKE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
