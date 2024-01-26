# $NetBSD: Makefile,v 1.9 2024/01/26 03:15:50 riastradh Exp $

DISTNAME=		enca-1.15
CATEGORIES=		converters
MASTER_SITES=		http://dl.cihar.com/enca/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/nijel/enca
COMMENT=		Extremely Naive Charset Analyser
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/enca.pc.in

USE_TOOLS+=		autoconf automake autoreconf
TOOL_DEPENDS+=		autoconf-archive>=0:../../devel/autoconf-archive
TOOL_DEPENDS+=		gettext-m4>=0:../../devel/gettext-m4
pre-configure:
	@${STEP_MSG} Rebuilding Makefiles
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
CONFIGURE_ARGS+=	CC_FOR_BUILD=${NATIVE_CC:Q}
CONFIGURE_ENV.NetBSD+=	ac_cv_file__dev_random=yes
CONFIGURE_ENV.NetBSD+=	ac_cv_file__dev_urandom=yes
CONFIGURE_ENV.NetBSD+=	ac_cv_file__dev_srandom=no
CONFIGURE_ENV.NetBSD+=	ac_cv_file__dev_arandom=no
.endif

.include "../../mk/bsd.pkg.mk"
