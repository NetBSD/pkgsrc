# $NetBSD: Makefile,v 1.6 2012/03/06 23:25:18 joerg Exp $
#

DISTNAME=	libtai-0.60
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://cr.yp.to/libtai/
COMMENT=	Library for storing and manipulating dates and times

DJB_RESTRICTED=	NO

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	nroff

EGDIR=		share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/leapsecs.dat ${PKG_SYSCONFDIR}/leapsecs.dat

INSTALLATION_DIRS=	bin include lib ${EGDIR}
INSTALLATION_DIRS+=	${PKGMANDIR}/man3

do-install:
	cd ${WRKSRC};							\
	for f in *.3; do						\
		${INSTALL_MAN} $${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3; \
	done;								\
	for f in easter nowutc leapsecs yearcal; do			\
		${INSTALL_PROGRAM} $${f} ${DESTDIR}${PREFIX}/bin;	\
	done;								\
	for f in *.h; do						\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/include;	\
	done;								\
	for f in libtai.a; do						\
		${INSTALL_LIB} $${f} ${DESTDIR}${PREFIX}/lib;		\
	done;								\
	for f in leapsecs.dat leapsecs.txt; do				\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/${EGDIR};	\
	done;								\

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
