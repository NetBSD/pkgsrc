# $NetBSD: Makefile,v 1.6 2003/04/19 03:51:24 uebayasi Exp $
#

DISTNAME=	canuum-1.0
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${CANNA_VER}/canuum
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/${CANNA_VER}5/
DISTFILES=	Uum${UUM_VER}.tar.gz ${CANNA_VER}.tar.gz

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/
COMMENT=	Japanese input tty frontend for Canna using uum

EXTRACT_ONLY=	Uum${UUM_VER}.tar.gz

USE_BUILDLINK2=	YES
MAKE_ARGS=	PREFIX=${PREFIX}

MAKE_ENV+=	CCOPTIONS="${CPPFLAGS}" EXTRA_LDOPTIONS="${LDFLAGS}"

UUM_VER=	4.109
CANNA_VER=	Canna36p1

post-extract:
	@${GTAR} -xzf ${DISTDIR}/${CANNA_VER}.tar.gz -C ${WRKDIR} \
		${CANNA_VER}/Canna.conf ${CANNA_VER}/canuum ${CANNA_VER}/canna
	@${MV} ${WRKDIR}/${CANNA_VER}/Canna.conf ${WRKSRC}
	@${CP} ${WRKDIR}/Uum${UUM_VER}/* ${WRKSRC}
	@${CP} ${WRKDIR}/${CANNA_VER}/canna/*.h ${WRKSRC}

pre-patch:
	@(cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < Canuum.patch)

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF_CMD}; \
		${MAKE} ${MAKE_ARGS} Makefile; \
		${MAKE} ${MAKE_ARGS} cannaconf.h; \
		${MAKE} ${MAKE_ARGS} depend)

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_ARGS} all)

pre-install:
	@${MKDIR} ${WRKSRC}/misc

post-install:
	@${INSTALL_MAN} ${WRKSRC}/canuum.jmn \
		${PREFIX}/man/ja_JP.EUC/man1/canuum.1

.include "../../devel/nbitools/buildlink2.mk"
.include "../../inputmethod/canna-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
