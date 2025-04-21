# $NetBSD: Makefile,v 1.17 2025/04/21 21:23:05 wiz Exp $

DISTNAME=	dog-1.7
PKGREVISION=	1
CATEGORIES=	misc
#MASTER_SITES=	http://jl.photodex.com/dog/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://jl.photodex.com/dog/
COMMENT=	Dog writes the contents of each given file, URL, or stdin

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

USE_TOOLS+=	gmake
BUILD_TARGET=	dog

.include "../../mk/bsd.prefs.mk"

LDFLAGS.SunOS+=	-lsocket -lnsl

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	OBJS="getopt.o getopt1.o"
.endif

.include "../../mk/bsd.pkg.mk"
