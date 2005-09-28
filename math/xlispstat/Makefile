# $NetBSD: Makefile,v 1.18 2005/09/28 20:52:24 rillig Exp $

DISTNAME=		xlispstat-3-52-18
PKGNAME=		xlispstat-3.52.18
CATEGORIES=		math lang
MASTER_SITES=		http://lib.stat.cmu.edu/xlispstat/Src/3-52/ \
			ftp://ftp.stat.umn.edu/pub/xlispstat/3-52/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.stat.umn.edu/~luke/xls/xlsinfo/xlsinfo.html
COMMENT=		Statistics/X11-based LISP interpreter

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

NOT_FOR_PLATFORM=	*-*-alpha	# core dumps

BUILD_TARGET=		xlispstat

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

MAKE_ENV+=		DISPLAY=	# Prevent 'Rejected connection'

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
