# $NetBSD: Makefile,v 1.3 2000/09/15 15:53:16 jlam Exp $
#

DISTNAME=		xboard-4.0.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNU:=xboard/}

MAINTAINER=		simonb@NetBSD.ORG

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf

GNU_CONFIGURE=		# defined
USE_PERL5=		# defined
USE_X11=		# defined
USE_XAW=		# defined
USE_XPM=		# defined

INFO_FILES=		xboard.info

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-Xaw3d
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=		-I${X11PREFIX}/include
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/bsd.pkg.mk"
