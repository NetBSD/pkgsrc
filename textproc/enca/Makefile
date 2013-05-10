# $NetBSD: Makefile,v 1.6 2013/05/10 05:27:38 riastradh Exp $
#

DISTNAME=		enca-1.14
CATEGORIES=		converters
MASTER_SITES=		http://dl.cihar.com/enca/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gitorious.org/enca
COMMENT=		Extremely Naive Charset Analyser
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/enca.pc.in

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS]) && ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_file__dev_random=yes
CONFIGURE_ENV+=		ac_cv_file__dev_urandom=yes
CONFIGURE_ENV+=		ac_cv_file__dev_srandom=no
CONFIGURE_ENV+=		ac_cv_file__dev_arandom=no
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

.include "../../mk/bsd.pkg.mk"
