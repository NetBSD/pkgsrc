# $NetBSD: Makefile,v 1.6 2001/12/28 07:35:30 tron Exp $

DISTNAME=		sh-utils-2.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=sh-utils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/shellutils/shellutils.html
COMMENT=		GNU shell utilities

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

USE_GMAKE=		YES
USE_GTEXINFO=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ENV+=		ac_cv_func_uname=no

.include "../../mk/bsd.pkg.mk"
