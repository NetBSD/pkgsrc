# $NetBSD: Makefile,v 1.22 2003/06/02 01:16:43 jschauma Exp $
#

DISTNAME=	catdoc-0.91.4
WRKSRC=		${WRKDIR}/catdoc
CATEGORIES=	textproc
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.fe.msk.ru/~vitus/catdoc/
COMMENT=	reads MS-Word file and puts out its content as plain text

DEPENDS=	tk>=8.3.2:../../x11/tk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share
CPPFLAGS+=	-Dunix -D__unix

.include "../../mk/bsd.pkg.mk"
