# $NetBSD: Makefile,v 1.15 2003/04/28 08:59:28 skrll Exp $
#

DISTNAME=	icu-2.4
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${PKGBASE}/source
CATEGORIES=	textproc
MASTER_SITES=	http://oss.software.ibm.com/icu/download/${PKGVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://oss.software.ibm.com/icu
COMMENT=	Robust and full-featured unicode support

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
TEST_TARGET=	check

.include "../../mk/endian.mk"

BIG_ENDIAN=
LITTLE_ENDIAN=
.if ${MACHINE_ENDIAN} == "little"
BIG_ENDIAN=	'@comment '
.elif ${MACHINE_ENDIAN} == "big"
LITTLE_ENDIAN=	'@comment '
.endif
PLIST_SUBST+=	BIG_ENDIAN=${BIG_ENDIAN}
PLIST_SUBST+=	LITTLE_ENDIAN=${LITTLE_ENDIAN}

PKG_SYSCONFSUBDIR=	icu

CONF_FILES+=	${PREFIX}/share/examples/icu/convrtrs.txt \
		${PKG_SYSCONFDIR}/convrtrs.txt

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-threads
CONFIGURE_ARGS+=	--enable-layout
CONFIGURE_ARGS+=	--enable-static

.include "../../mk/bsd.pkg.mk"
