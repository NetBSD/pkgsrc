# $NetBSD: Makefile,v 1.30 2004/04/04 16:58:16 recht Exp $
#

DISTNAME=	icu-2.8
CATEGORIES=	textproc
#
# The IBM site has long delays that can cause ftp to timeout.  Use the
# backup FTP repositories in preference to the IBM one.
#
#MASTER_SITES=	${MASTER_SITE_BACKUP} \
#		ftp://www-126.ibm.com/pub/icu/${PKGVERSION}/
MASTER_SITES=	ftp://www-126.ibm.com/pub/icu/${PKGVERSION}/

EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://oss.software.ibm.com/icu/
COMMENT=	Robust and full-featured Unicode services

WRKSRC=			${WRKDIR}/${PKGBASE}/source
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_LANGUAGES=		c c++
TEST_TARGET=		check

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static

# ICU's configure script will automatically append "/icu" to the sysconfdir.
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
PKG_SYSCONFSUBDIR=	icu

CONVRTRS_EG=		${CONVRTRS_EG_DIR}/convrtrs.txt
CONVRTRS_EG_DIR=	${PREFIX}/share/examples/icu

SUPPORT_FILES+=		${CONVRTRS_EG} ${PKG_SYSCONFDIR}/convrtrs.txt

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "native"
CONFIGURE_ARGS+=	--disable-threads
.endif

post-install:
	${INSTALL_DATA_DIR} ${CONVRTRS_EG_DIR}
	${INSTALL_DATA} ${WRKSRC}/data/mappings/convrtrs.txt ${CONVRTRS_EG}

.include "../../mk/bsd.pkg.mk"
