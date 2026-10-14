# $NetBSD: Makefile,v 1.1 2026/10/14 08:16:40 drixter Exp $

DISTNAME=		apl-2.0
PKGNAME=		gnu-${DISTNAME}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=apl/}

MAINTAINER=		drixter@e-utp.net
HOMEPAGE=		https://ftp.jaist.ac.jp/pub/GNU/apl/
COMMENT=		Free interpreter for the programming language APL
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
INFO_FILES+=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++20

CONFIGURE_ARGS+=	--program-prefix=gnu-
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	CORE_COUUNT_WANTED=argv
MAKE_ENV+=		MAKE_J=${MAKE_JOBS:U1}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	${PKGBASE}.d
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}
APLD_CONFFILES=		keyboard1.txt parallel_thresholds preferences
.for conf in ${APLD_CONFFILES}
CONF_FILES+=		${EGDIR}/${PKGBASE}.d/${conf} \
			${PKG_SYSCONFDIR}/${conf}
.endfor

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS:M*BSD}
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
