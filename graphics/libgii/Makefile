# $NetBSD: Makefile,v 1.3 2002/11/25 20:16:26 jlam Exp $
#

DISTNAME=	libgii-0.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/current/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Input Interface - API for all possible input sources

USE_BUILDLINK2=		# defined
USE_X11=		# defined

USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-mutexes=int
CONFIGURE_ARGS+=	--with-x

.include "../../mk/bsd.pkg.mk"
