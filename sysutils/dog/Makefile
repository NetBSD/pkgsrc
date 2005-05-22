# $NetBSD: Makefile,v 1.10 2005/05/22 20:08:32 jlam Exp $

DISTNAME=	dog-1.7
CATEGORIES=	misc
MASTER_SITES=	http://jl.photodex.com/dog/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jl.photodex.com/dog/
COMMENT=	Dog writes the contents of each given file, URL, or stdin

USE_TOOLS+=	gmake
BUILD_TARGET=	dog

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl
MAKE_ENV+=	OBJS="getopt.o getopt1.o"
.endif

.include "../../mk/bsd.pkg.mk"
