# $NetBSD: Makefile,v 1.3.2.2 2002/06/23 18:47:27 jlam Exp $
#

DISTNAME=	canuum-1.0
PKGREVISION=	1
CATEGORIES=	japanese inputmethod
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/
DISTFILES=	Uum4.109.tar.gz Canna35b2.tar.gz
EXTRACT_ONLY=	Uum4.109.tar.gz

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/
COMMENT=	Japanese input tty frontend for Canna using uum

MANLANG=	ja
MAN1=		canuum.1
MAKE_ARGS=	PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/Canna35b2/canuum

MAKE_ENV+=	CCOPTIONS="${CPPFLAGS}" EXTRA_LDOPTIONS="${LDFLAGS}"

post-extract:
	@${GTAR} -xzf ${DISTDIR}/Canna35b2.tar.gz -C ${WRKDIR} \
		Canna35b2/Canna.conf Canna35b2/canuum
	@${MV} ${WRKDIR}/Canna35b2/Canna.conf ${WRKSRC}/
	@${CP} ${WRKDIR}/Uum4.109/* ${WRKSRC}

pre-patch:
	@(cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < Canuum.patch)

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF_CMD}; \
		${MAKE} ${MAKE_ARGS} Makefile; \
		${MAKE} ${MAKE_ARGS} cannaconf.h; ${MAKE} ${MAKE_ARGS} depend)

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_ARGS} all)

post-install:
	@${INSTALL_MAN} ${WRKSRC}/canuum.jmn \
		${PREFIX}/man/ja_JP.EUC/man1/canuum.1

.include "../../devel/nbitools/nbitools.mk"
.include "../canna-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
