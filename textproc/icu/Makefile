# $NetBSD: Makefile,v 1.17 2003/06/20 09:55:55 jlam Exp $
#

DISTNAME=	icu-2.4
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGBASE}/source
CATEGORIES=	textproc
MASTER_SITES=	http://oss.software.ibm.com/icu/download/${PKGVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://oss.software.ibm.com/icu
COMMENT=	Robust and full-featured unicode support

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
TEST_TARGET=	check

PKG_SYSCONFSUBDIR=	icu

SUPPORT_FILES+=	${PREFIX}/share/examples/icu/convrtrs.txt \
		${PKG_SYSCONFDIR}/convrtrs.txt

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--enable-layout
CONFIGURE_ARGS+=	--enable-static

.include "../../mk/bsd.pkg.mk"
