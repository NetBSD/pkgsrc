# $NetBSD: Makefile,v 1.30 2026/08/04 20:29:08 wiz Exp $

DISTNAME=	SNNSv4.3
PKGNAME=	snns-4.3
PKGREVISION=	2
CATEGORIES=	math
#MASTER_SITES=	http://www-ra.informatik.uni-tuebingen.de/downloads/SNNS/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www-ra.informatik.uni-tuebingen.de/SNNS/
COMMENT=	Software simulator for neural networks

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-global
# random errors about missing LEARN_Tacoma
MAKE_JOBS_SAFE=		no

CFLAGS+=	-Wno-implicit-function-declaration
CFLAGS+=	-Wno-implicit-int

XGUILOADPATH=	${PREFIX}/share/snns

INSTALLATION_DIRS+=	share/snns share/doc/snns \
			share/examples/snns

INSTALL_TARGET=		install install-man
INSTALL_MAKE_FLAGS+=	INSTALLDIR=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

# does not directly support Xaw3d
.PHONY: buildlink-Xaw3d-inc-hack
pre-configure: buildlink-Xaw3d-inc-hack

buildlink-Xaw3d-inc-hack: buildlink-directories
	cd ${BUILDLINK_DIR}/include/X11 && ln -s Xaw3d Xaw

post-install:
	${INSTALL_DATA} ${WRKSRC}/help.hdoc ${DESTDIR}${XGUILOADPATH}
	${INSTALL_DATA} ${WRKSRC}/default.cfg ${DESTDIR}${XGUILOADPATH}
	for i in `ls -1 ${WRKSRC}/tools/doc`; do \
		${INSTALL_DATA} ${WRKSRC}/tools/doc/$$i \
			${DESTDIR}${PREFIX}/share/doc/snns; \
	done
	for i in `ls -1 ${WRKSRC}/examples`; do \
		${INSTALL_DATA} ${WRKSRC}/examples/$$i \
		    ${DESTDIR}${PREFIX}/share/examples/snns; \
	done

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/libXaw3d/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
