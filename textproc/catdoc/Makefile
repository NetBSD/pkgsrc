# $NetBSD: Makefile,v 1.13 2000/04/17 10:30:01 jdolecek Exp $
#

DISTNAME=	catdoc-0.91.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/contrib/

MAINTAINER=	packages@netbsd.org

DEPENDS=	tk-[0-9]*:../../x11/tk80

WRKSRC=		${WRKDIR}/catdoc

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share
CPPFLAGS+=	-Dunix -D__unix
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
