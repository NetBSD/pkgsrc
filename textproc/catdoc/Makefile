# $NetBSD: Makefile,v 1.15 2000/08/30 15:51:59 jwise Exp $
#

DISTNAME=	catdoc-0.91.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	packages@netbsd.org

DEPENDS=	tk-8.3.2:../../x11/tk

WRKSRC=		${WRKDIR}/catdoc

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share
CPPFLAGS+=	-Dunix -D__unix
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
