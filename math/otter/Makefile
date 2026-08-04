# $NetBSD: Makefile,v 1.20 2026/08/04 20:29:07 wiz Exp $

DISTNAME=	otter-3.0.6
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://www.cs.unm.edu/~mccune/otter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.unm.edu/~mccune/otter/
COMMENT=	Automated Deduction System
LICENSE=	public-domain

BUILD_DIRS=	source
BUILD_TARGET=	otter

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/otter ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} Announce Changelog		\
		Copying README* ${DESTDIR}${PREFIX}/share/doc/otter
	for d in auto fringe ivy kalman misc program split wos;	do	\
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/otter/$$d;\
	${INSTALL_DATA} ${WRKSRC}/examples/$$d/*			\
		${DESTDIR}${PREFIX}/share/examples/otter/$$d;		\
	done
	cd ${WRKSRC}/examples && ${INSTALL_DATA} Run_all \
		objects	summary ${DESTDIR}${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKSRC}/examples/README 			\
		${DESTDIR}${PREFIX}/share/examples/otter
	${INSTALL_DATA} ${WRKSRC}/document/* 				\
		${DESTDIR}${PREFIX}/share/doc/otter

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
