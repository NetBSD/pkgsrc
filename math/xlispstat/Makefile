# $NetBSD: Makefile,v 1.14 2004/04/24 22:46:11 jlam Exp $
# FreeBSD Id: Makefile,v 1.7 1998/08/20 07:35:21 asami Exp
#

DISTNAME=		xlispstat-3-52-18
PKGNAME=		xlispstat-3.52.18
CATEGORIES=		math lang
MASTER_SITES=		http://lib.stat.cmu.edu/xlispstat/Src/3-52/ \
			ftp://ftp.stat.umn.edu/pub/xlispstat/3-52/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.stat.umn.edu/~luke/xls/xlsinfo/xlsinfo.html
COMMENT=		Statistics/X11-based LISP interpreter

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined

NOT_FOR_PLATFORM=	*-*-alpha	# core dumps

ALL_TARGET=		xlispstat

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

MAKE_ENV+=		DISPLAY=	# Prevent 'Rejected connection'

.include "../../mk/bsd.pkg.mk"
