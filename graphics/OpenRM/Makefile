# $NetBSD: Makefile,v 1.35 2022/06/28 11:33:59 wiz Exp $
#

DISTNAME=		openrm-devel-1.5.2
PKGNAME=		OpenRM-1.5.2
PKGREVISION=		17
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openrm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.openrm.org/
COMMENT=		The OpenRM Scene Graph API

WRKSRC=			${WRKDIR}/rm152
CFLAGS+=		-I${X11BASE}/include
BUILD_TARGET=		libtool docs
USE_LIBTOOL=		yes
USE_TOOLS+=		csh perl
REPLACE_PERL=		doc/sortlist.pl doc/source2html.pl

CHECK_PORTABILITY_SKIP+=	bin/mklib.linux # uses [[, not used

ALL_ENV+=		REAL_CC=${CC}

DOCDIR=			${PREFIX}/share/doc/OpenRM
INSTALLATION_DIRS=	lib

do-configure:
	${CHMOD} +x ${WRKSRC}/bin/mklib.libtool

do-install:
	# install libraries
	for name in rm rmaux rmi rmv; do				\
		${LIBTOOL} --mode=install ${INSTALL_LIB}		\
		 ${WRKSRC}/$$name/lib$$name.la ${DESTDIR}${PREFIX}/lib;	\
	done
	# install includes
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/rm
	${INSTALL_DATA} ${WRKSRC}/include/rm/*.h ${DESTDIR}${PREFIX}/include/rm
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/FUTUREPLANS ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASENOTES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/*.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/images/* ${DESTDIR}${DOCDIR}/images

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
