# $NetBSD: Makefile,v 1.17 2004/05/02 03:19:50 snj Exp $

DISTNAME=		guile-1.4.1
PKGNAME=		guile14-1.4.1
PKGREVISION=		4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
NO_MTREE=		YES
USE_LIBTOOL=		YES
USE_GNU_READLINE=	YES

INFO_FILES=		guile.info

BUILDLINK_PASSTHRU_DIRS=${PREFIX}/guile/1.4/lib

# Link the native thread so that Guile processes won't die when libpthread.so
# is dl_open(3)'ed.
CFLAGS+=		${PTHREAD_CFLAGS}

.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX=			${LOCALBASE}/guile/1.4
