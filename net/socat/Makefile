# $NetBSD: Makefile,v 1.48 2022/07/23 15:40:33 leot Exp $

DISTNAME=	socat-1.7.4.3
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://www.dest-unreach.org/socat/
COMMENT=	"netcat++" (extended design, new implementation)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES

USE_TOOLS+=	bash:test
REPLACE_BASH+=	*.sh

TEST_TARGET=	test

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-libwrap

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS]) && ${OPSYS} == "NetBSD"
# XXX Kludge -- the right fix is to make socat not depend on these constants.
CONFIGURE_ENV+=		sc_cv_sys_crdly_shift=-1
CONFIGURE_ENV+=		sc_cv_sys_tabdly_shift=-1
CONFIGURE_ENV+=		sc_cv_sys_csize_shift=8
CONFIGURE_ENV+=		ac_cv_ispeed_offset=9
.endif

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doc/socat.1
SUBST_SED.paths=	-e 's,/usr/,${PREFIX}/,g'

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
