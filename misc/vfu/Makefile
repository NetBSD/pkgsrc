# $NetBSD: Makefile,v 1.1.1.1 1999/01/26 23:31:46 hubertf Exp $
#

DISTNAME=	vful141s
PKGNAME=	vfu-1.41
EXTRACT_SUFX=	.tgz
CATEGORIES=	misc
MASTER_SITES=	http://www.biscom.net/~cade/away/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.biscom.net/~cade/vfu/

DEPENDS=	ncurses-1.9.9g:../../devel/ncurses

WRKSRC=		${WRKDIR}/${PKGNAME}

do-build:
	@cd ${WRKSRC}/vslib ; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	@cd ${WRKSRC}/vfu ; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vfu/vfu \
		${PREFIX}/bin
	${INSTALL_DATA_DIR}	${PREFIX}/share/doc/vfu
	${INSTALL_DATA} \
		${WRKSRC}/vfu/COPYING \
		${WRKSRC}/vfu/INSTALL \
		${WRKSRC}/vfu/README \
		${WRKSRC}/vfu/vfu.txt \
		${WRKSRC}/vfu/readme \
		${WRKSRC}/vfu/COPYING \
		${WRKSRC}/vfu/COPYING \
		${PREFIX}/share/doc/vfu
	${INSTALL_DATA} \
		${WRKSRC}/vfu/vfurc \
		${PREFIX}/share/doc/vfu/vfurc.example
	[ -f ${PREFIX}/etc/vfurc ] || \
		${INSTALL_DATA} \
		 ${PREFIX}/share/doc/vfu/vfurc.example ${PREFIX}/etc/vfurc

.include "../../mk/bsd.pkg.mk"
