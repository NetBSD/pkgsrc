# $NetBSD: Makefile,v 1.12 2006/11/28 16:42:51 tv Exp $

DISTNAME=	dog-1.7
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://jl.photodex.com/dog/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jl.photodex.com/dog/
COMMENT=	Dog writes the contents of each given file, URL, or stdin

USE_TOOLS+=	gmake
BUILD_TARGET=	dog

.include "../../mk/bsd.prefs.mk"

LDFLAGS.SunOS+=	-lsocket -lnsl

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Interix"
MAKE_ENV+=	OBJS="getopt.o getopt1.o"
.endif

.include "../../mk/bsd.pkg.mk"
