# $NetBSD: Makefile,v 1.5 2001/12/20 06:17:39 tron Exp $

DISTNAME=		sh-utils-2.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=sh-utils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/shellutils/shellutils.html
COMMENT=		GNU shell utilities

USE_GMAKE=		YES
USE_GTEXINFO=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ENV+=		ac_cv_func_uname=no

.include "../../mk/bsd.pkg.mk"
