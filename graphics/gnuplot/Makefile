# $NetBSD: Makefile,v 1.20 2003/06/06 14:41:29 jschauma Exp $
#

DISTNAME=	gnuplot-3.7.3
SVR4_PKGNAME=	gplot
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot/} \
		ftp://ftp.ucc.ie/pub/gnuplot/ \
		ftp://ftp.cc.monash.edu.au/pub/gnuplot/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://sourceforge.net/projects/gnuplot/
COMMENT=	gnuplot is a nice plotting utility

USE_BUILDLINK2=		YES
# because of missing rl_complete_with_tilde_expansion and rl_terminal_name
USE_GNU_READLINE=	YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-pdf
CONFIGURE_ARGS+=	--with-plot=${LOCALBASE}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE})
PKGNAME=                ${DISTNAME:C/-/-x11-/}
CONFLICTS+=             ${DISTNAME:C/-[0-9].*//}
USE_X11=		YES
PLIST_SUBST+=		XCOMM=""
.else
CONFLICTS+=             ${DISTNAME:C/-[0-9].*/-x11/}
PLIST_SUBST+=		XCOMM="@comment "
.endif

.include "../../devel/readline/buildlink2.mk"
.include "../../graphics/plotutils/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/pdflib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
