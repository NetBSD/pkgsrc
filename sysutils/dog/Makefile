# $NetBSD: Makefile,v 1.8 2004/12/03 15:15:10 wiz Exp $
# FreeBSD Id: ports/misc/dog/Makefile,v 1.1 2000/06/10 05:45:34 will Exp

DISTNAME=	dog-1.7
CATEGORIES=	misc
MASTER_SITES=	http://jl.photodex.com/dog/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jl.photodex.com/dog/
COMMENT=	Dog writes the contents of each given file, URL, or stdin

USE_GNU_TOOLS+=	make
BUILD_TARGET=	dog

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl
MAKE_ENV+=	OBJS="getopt.o getopt1.o"
.endif

.include "../../mk/bsd.pkg.mk"
