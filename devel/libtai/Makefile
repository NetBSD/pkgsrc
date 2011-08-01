# $NetBSD: Makefile,v 1.5 2011/08/01 05:37:12 dholland Exp $
#

DISTNAME=	libtai-0.60
PKGREVISION=	2
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
INSTALLATION_DIRS+=	${PKGMANDIR}/man3 ${PKGMANDIR}/cat3

do-install:
	cd ${WRKSRC};							\
	for f in *.3; do						\
		${INSTALL_MAN} $${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3; \
	done;								\
	for f in *.0; do						\
		${INSTALL_MAN} $${f} ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat3; \
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
