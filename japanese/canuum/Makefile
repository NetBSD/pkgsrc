# $NetBSD: Makefile,v 1.2 1999/08/27 04:11:35 sakamoto Exp $
#

DISTNAME=	canuum-1.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna35/
DISTFILES=	Uum4.109.tar.gz Canna35b2.tar.gz
EXTRACT_ONLY=	Uum4.109.tar.gz

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.nec.co.jp/japanese/product/computer/soft/canna/

DEPENDS=	Canna-lib-3.5b2:../../japanese/canna-lib

MANLANG=	ja
MAN1=		canuum.1
MAKE_ARGS=	PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/Canna35b2/canuum

post-extract:
	@${GTAR} -xzf ${DISTDIR}/Canna35b2.tar.gz -C ${WRKDIR} \
		Canna35b2/Canna.conf Canna35b2/canuum
	@${MV} ${WRKDIR}/Canna35b2/Canna.conf ${WRKSRC}/
	@${CP} ${WRKDIR}/Uum4.109/* ${WRKSRC}

pre-patch:
	@(cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < Canuum.patch)

do-configure:
	@(cd ${WRKSRC}; xmkmf; ${MAKE} ${MAKE_ARGS} Makefile; \
	${MAKE} ${MAKE_ARGS} cannaconf.h; ${MAKE} ${MAKE_ARGS} depend)

do-build:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_ARGS} all)

post-install:
	@${INSTALL_MAN} ${WRKSRC}/canuum.jmn ${PREFIX}/man/ja_JP.EUC/man1/canuum.1

.include "../../mk/bsd.pkg.mk"
