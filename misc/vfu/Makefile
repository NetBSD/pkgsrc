# $NetBSD: Makefile,v 1.10 1999/07/06 08:05:51 jlam Exp $
#

DISTNAME=	vfu-1.51
CATEGORIES=	misc
MASTER_SITES=	http://www.biscom.net/~cade/away/
EXTRACT_SUFX=	-source.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.biscom.net/~cade/vfu/

DEPENDS=	ncurses-4.2:../../devel/ncurses

MAKE_FLAGS+=	CCDEF="-DVFU_RCPATH1=\\\"${PREFIX}/etc/\\\" -DVFU_RCPATH2=\\\"${PREFIX}/\\\" -D__unix__" \
		LDDEF="${LDFLAGS}"

do-build:
	cd ${WRKSRC}/vslib ; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/vfu ; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/ftparc ; \
	 ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vfu/vfu  ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ftparc/ftparc  ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vfu
	${INSTALL_DATA} \
		${WRKSRC}/COPYING \
		${WRKSRC}/INSTALL \
		${WRKSRC}/vfu/README \
		${WRKSRC}/VFU.txt \
		${PREFIX}/share/doc/vfu
	${INSTALL_DATA} \
		${WRKSRC}/vfu.conf \
		${PREFIX}/share/doc/vfu/vfurc.example
	[ -f ${PREFIX}/etc/vfurc ] || \
		${INSTALL_DATA} \
		 ${PREFIX}/share/doc/vfu/vfurc.example ${PREFIX}/etc/vfurc

.include "../../mk/bsd.pkg.mk"
