# $NetBSD: Makefile,v 1.19 2001/05/08 16:12:07 agc Exp $
#

DISTNAME=	catdoc-0.91.4
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fe.msk.ru/~vitus/catdoc/
COMMENT=	reads MS-Word file and puts out its content as plain text

DEPENDS=	tk>=8.3.2:../../x11/tk

WRKSRC=		${WRKDIR}/catdoc

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share
CPPFLAGS+=	-Dunix -D__unix
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
