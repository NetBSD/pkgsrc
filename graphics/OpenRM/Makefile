# $NetBSD: Makefile,v 1.11 2005/06/24 21:07:08 jlam Exp $
#

DISTNAME=		openrm-devel-1.5.2
PKGNAME=		OpenRM-1.5.2
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openrm/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.openrm.org/
COMMENT=		The OpenRM Scene Graph API

WRKSRC=			${WRKDIR}/rm152
CFLAGS+=		-I${X11BASE}/include
BUILD_TARGET=		libtool docs
USE_LIBTOOL=		yes
USE_TOOLS+=		csh perl
REPLACE_PERL=		doc/sortlist.pl doc/source2html.pl

DOCDIR=			${PREFIX}/share/doc/OpenRM
INSTALLATION_DIRS=	lib

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

do-configure:
	${CHMOD} +x ${WRKSRC}/bin/mklib.libtool

do-install:
	# install libraries
	for name in rm rmaux rmi rmv; do				\
		${LIBTOOL} --mode=install ${INSTALL_LIB}		\
			${WRKSRC}/$$name/lib$$name.la ${PREFIX}/lib;	\
	done
	# install includes
	${INSTALL_DATA_DIR} ${PREFIX}/include/rm
	${INSTALL_DATA} ${WRKSRC}/include/rm/*.h ${PREFIX}/include/rm
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/FUTUREPLANS ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASENOTES ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/*.html ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/HTML/images/* ${DOCDIR}/images

.include "../../mk/bsd.pkg.mk"
