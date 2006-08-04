# $NetBSD: Makefile,v 1.20 2006/08/04 15:09:51 tron Exp $

DISTNAME=	xvidcore-1.1.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xvid.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xvid.org/
COMMENT=	ISO MPEG-4 compliant video codec

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	nasm>=0.98.34:../../devel/nasm
.elif ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=	yasm>=0.4.0:../../devel/yasm
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME}/build/generic
GNU_CONFIGURE=	YES

MAKE_ENV+=	MKDIR=${MKDIR:Q}

.if ${OPSYS} == "Darwin"
post-install:
	${RM} -f ${PREFIX}/lib/libxvidcore.so.4
.endif

.include "../../mk/bsd.pkg.mk"
