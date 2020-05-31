# $NetBSD: Makefile,v 1.10 2020/05/31 17:07:59 rillig Exp $
#

.include "../../databases/qdbm/Makefile.common"

PKGNAME=	qdbm-cgi-0.0.1.${QDBM_VERSION}
CATEGORIES=	databases www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fallabs.com/qdbm/cgispex.html
COMMENT=	CGI scripts of QDBM
LICENSE=	gnu-lgpl-v2.1

MY_SUBDIR=	cgi
BUILD_DIRS=	${MY_SUBDIR}
CONFIGURE_DIRS=	${MY_SUBDIR}

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PTHREAD=	no

.include "../../databases/qdbm/buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	${MY_SUBDIR}/configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.endif
.include "../../mk/bsd.pkg.mk"
