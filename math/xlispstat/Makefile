# $NetBSD: Makefile,v 1.7 1999/08/06 13:30:42 agc Exp $
# FreeBSD Id: Makefile,v 1.7 1998/08/20 07:35:21 asami Exp
#

DISTNAME=		xlispstat-3-52-9
PKGNAME=		xlispstat-3.52.9
CATEGORIES=		math lang
MASTER_SITES=		ftp://ftp.stat.umn.edu/pub/xlispstat/3-52/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.stat.umn.edu/~luke/xls/xlsinfo/xlsinfo.html

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

NOT_FOR_PLATFORM=	*-*-alpha	#core dumps

ALL_TARGET=		xlispstat

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

.include "../../mk/bsd.pkg.mk"
