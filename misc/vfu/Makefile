# $NetBSD: Makefile,v 1.8 1999/04/11 17:51:31 hubertf Exp $
#

PKGNAME=	vfu-1.50
DISTNAME=	${PKGNAME}-source
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	misc
MASTER_SITES=	http://www.biscom.net/~cade/away/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.biscom.net/~cade/vfu/

DEPENDS=	ncurses-1.9.9g:../../devel/ncurses

MAKE_FLAGS+=	CCDEF="-I${LOCALBASE}/include -DVFU_RCPATH1=\\\"${PREFIX}/etc/\\\" -DVFU_RCPATH2=\\\"${PREFIX}/\\\"" \
		LDDEF="-L${LOCALBASE}/lib"

do-build:
	cd ${WRKSRC}/vslib ; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/vfu ; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vfu/vfu \
		${PREFIX}/bin
	${INSTALL_DATA_DIR}	${PREFIX}/share/doc/vfu
	${INSTALL_DATA} \
		${WRKSRC}/vfu/COPYING \
		${WRKSRC}/vfu/INSTALL \
		${WRKSRC}/vfu/README \
		${WRKSRC}/vfu/VFU.txt \
		${PREFIX}/share/doc/vfu
	${INSTALL_DATA} \
		${WRKSRC}/vfu.conf \
		${PREFIX}/share/doc/vfu/vfurc.example
	[ -f ${PREFIX}/etc/vfurc ] || \
		${INSTALL_DATA} \
		 ${PREFIX}/share/doc/vfu/vfurc.example ${PREFIX}/etc/vfurc

.include "../../mk/bsd.pkg.mk"
