# $NetBSD: Makefile,v 1.4 2000/10/15 02:14:20 jlam Exp $
#

DISTNAME=		xboard-4.1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNU:=xboard/}

MAINTAINER=		simonb@NetBSD.ORG
HOMEPAGE=		http://www.research.compaq.com/SRC/personal/mann/xboard.html

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf

USE_PERL5=		# defined
USE_X11=		# defined
USE_XAW=		# defined
USE_XPM=		# defined

INFO_FILES=		xboard.info

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-xpm
CONFIGURE_ARGS+=	--enable-zippy		# interface to ICS
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${X11PREFIX}/include

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-Xaw3d
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/bsd.pkg.mk"
