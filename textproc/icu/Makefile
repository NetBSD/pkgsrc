# $NetBSD: Makefile,v 1.18 2003/06/23 07:49:39 jlam Exp $
#

DISTNAME=	icu-2.6
WRKSRC=		${WRKDIR}/${PKGBASE}/source
CATEGORIES=	textproc
MASTER_SITES=	ftp://www-126.ibm.com/pub/icu/${PKGVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://oss.software.ibm.com/icu/
COMMENT=	robust and full-featured Unicode services

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
