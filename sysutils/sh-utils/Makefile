# $NetBSD: Makefile,v 1.10 2003/02/13 17:38:58 grant Exp $

DISTNAME=		sh-utils-2.0
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=sh-utils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/shellutils/shellutils.html
COMMENT=		GNU shell utilities

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_PERL5=		build
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX
.endif
CONFIGURE_ENV+=		ac_cv_func_uname=no

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
