# $NetBSD: Makefile,v 1.4 2001/10/12 21:20:37 tron Exp $

DISTNAME=		sh-utils-2.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=sh-utils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/shellutils/shellutils.html
COMMENT=		GNU shell utilities

USE_GTEXINFO=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ENV+=		ac_cv_func_uname=no

.include "../../mk/bsd.pkg.mk"
