# $NetBSD: Makefile,v 1.14 2003/09/28 09:13:57 jlam Exp $

DISTNAME=		guile-1.4.1
PKGNAME=		guile14-1.4.1
PKGREVISION=		4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
NO_MTREE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/guile-readline/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libltdl/libtool

USE_GNU_READLINE=	YES

INFO_FILES=		guile.info

# Link the native thread so that Guile processes won't die when libpthread.so
# is dl_open(3)'ed.
CFLAGS+=		${PTHREAD_CFLAGS}

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX=			${LOCALBASE}/guile/1.4
