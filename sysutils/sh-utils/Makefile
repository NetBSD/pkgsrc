# $NetBSD: Makefile,v 1.9 2002/07/24 19:45:28 jlam Exp $

DISTNAME=		sh-utils-2.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=sh-utils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/shellutils/shellutils.html
COMMENT=		GNU shell utilities

USE_PERL5=		build
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ARGS+=	--program-transform-name='s,^gid,gnuid,'
CONFIGURE_ENV+=		ac_cv_func_uname=no

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
