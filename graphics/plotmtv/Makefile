# $NetBSD: Makefile,v 1.1.1.1 2000/11/25 21:06:04 jtb Exp $

DISTNAME=	Plotmtv1.4.1
PKGNAME=	plotmtv-1.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jtb@netbsd.org

WRKSRC=		${WRKDIR}/Plotmtv1.4.1

USE_IMAKE=	YES
USE_X11_BASE=	YES

pre-build:
	@(cd ${WRKDIR}/Plotmtv1.4.1; ${MV} -f Docs/plotmtv.man Plot/;)

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/plotmtv
	@(cd ${WRKDIR}/Plotmtv1.4.1/Tests/;			\
	for i in *.mtv;						\
	do							\
	${INSTALL_DATA} $$i ${PREFIX}/share/examples/plotmtv;	\
	done;							\
	for i in run.sh run.csh;				\
	do							\
	${INSTALL_SCRIPT} $$i ${PREFIX}/share/examples/plotmtv; \
	done;)

.include "../../mk/bsd.pkg.mk"
