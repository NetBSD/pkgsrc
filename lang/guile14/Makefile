# $NetBSD: Makefile,v 1.29 2006/03/16 23:52:30 jlam Exp $

DISTNAME=		guile-1.4.1
PKGNAME=		guile14-1.4.1
PKGREVISION=		8
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension (old version)

GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/1.4
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
USE_GNU_READLINE=	YES
PTHREAD_AUTO_VARS=	YES

INFO_DIR=		guile/1.4/info
INFO_FILES=		guile.info

BUILDLINK_PASSTHRU_DIRS=	${PREFIX}/guile/1.4

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
