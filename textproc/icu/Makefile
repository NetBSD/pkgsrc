# $NetBSD: Makefile,v 1.22 2003/10/18 12:46:37 cjep Exp $
#

DISTNAME=	icu-2.6
WRKSRC=		${WRKDIR}/${PKGBASE}/source
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

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
TEST_TARGET=		check

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--disable-threads

# ICU's configure script will automatically append "/icu" to the sysconfdir.
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
PKG_SYSCONFSUBDIR=	icu

SUPPORT_FILES+=		${PREFIX}/share/examples/icu/convrtrs.txt \
			${PKG_SYSCONFDIR}/convrtrs.txt

.include "../../mk/bsd.pkg.mk"
