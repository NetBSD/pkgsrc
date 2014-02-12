# $NetBSD: Makefile,v 1.31 2014/02/12 23:18:26 tron Exp $

DISTNAME=	socat-1.7.2.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dest-unreach.org/socat/
COMMENT=	"netcat++" (extended design, new implementation)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
ONLY_FOR_COMPILER=	gcc	# uses -Werror in the configure script

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-libwrap
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS]) && ${OPSYS} == "NetBSD"
# XXX Kludge -- the right fix is to make socat not depend on these constants.
CONFIGURE_ENV+=		sc_cv_sys_crdly_shift=-1
CONFIGURE_ENV+=		sc_cv_sys_tabdly_shift=-1
CONFIGURE_ENV+=		sc_cv_sys_csize_shift=8
CONFIGURE_ENV+=		ac_cv_ispeed_offset=9
.endif

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	doc/socat.1
SUBST_SED.paths=	-e 's,/usr/,${PREFIX}/,g'

SUBST_CLASSES+=		makefile
SUBST_MESSAGE.makefile=	Fixing Makefile CCOPTS.
SUBST_STAGE.makefile=	post-patch
SUBST_FILES.makefile=	Makefile.in
SUBST_SED.makefile=	-e '/CCOPTS/ s/-Wall -Wno-parentheses//'

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
