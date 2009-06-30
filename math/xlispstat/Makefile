# $NetBSD: Makefile,v 1.23 2009/06/30 00:07:20 joerg Exp $

DISTNAME=		xlispstat-3-52-20
PKGNAME=		xlispstat-3.52.20
CATEGORIES=		math lang
MASTER_SITES=		http://lib.stat.cmu.edu/xlispstat/Src/3-52/ \
			ftp://ftp.stat.umn.edu/pub/xlispstat/3-52/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.stat.uiowa.edu/~luke/xls/xlsinfo/
COMMENT=		Statistics/X11-based LISP interpreter

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

NOT_FOR_PLATFORM=	*-*-alpha	# core dumps

BUILD_TARGET=		xlispstat

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CPPFLAGS=
.endif

MAKE_ENV+=		DISPLAY=	# Prevent 'Rejected connection'

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
