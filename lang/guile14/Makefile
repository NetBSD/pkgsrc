# $NetBSD: Makefile,v 1.22 2004/11/30 17:57:03 wiz Exp $

DISTNAME=		guile-1.4.1
PKGNAME=		guile14-1.4.1
PKGREVISION=		6
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${LOCALBASE}/guile/1.4
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_GNU_READLINE=	YES
PTHREAD_AUTO_VARS=	YES

INFO_DIR=		guile/1.4/info
INFO_FILES=		guile.info

BUILDLINK_PASSTHRU_DIRS=	${LOCALBASE}/guile/1.4

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
