# $NetBSD: Makefile,v 1.27 2004/01/20 12:26:49 agc Exp $
#

DISTNAME=	icu-2.6.1
CATEGORIES=	textproc
#
# The IBM site has long delays that can cause ftp to timeout.  Use the
# backup FTP repositories in preference to the IBM one.
#
MASTER_SITES=	${MASTER_SITE_BACKUP} \
		ftp://www-126.ibm.com/pub/icu/${PKGVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://oss.software.ibm.com/icu/
COMMENT=	Robust and full-featured Unicode services

WRKSRC=			${WRKDIR}/${PKGBASE}/source
USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
TEST_TARGET=		check

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static

# ICU's configure script will automatically append "/icu" to the sysconfdir.
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
PKG_SYSCONFSUBDIR=	icu

SUPPORT_FILES+=		${PREFIX}/share/examples/icu/convrtrs.txt \
			${PKG_SYSCONFDIR}/convrtrs.txt

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.prefs.mk"

.if !empty(CC_VERSION:Mgcc-3*)
CXXFLAGS:=		${CXXFLAGS:C/-O[0-9]*/-O/g}
CFLAGS:=		${CFLAGS:C/-Os/-O/g}
CXXFLAGS:=		${CXXFLAGS:C/-Os/-O/g}
CFLAGS:=		${CFLAGS:C/-O[0-9]*/-O/g}
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS}"
CONFIGURE_ENV+=		CFLAGS="${CFLAGS}"
.endif

.include "../../mk/bsd.pkg.mk"
