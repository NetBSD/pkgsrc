# $NetBSD: Makefile,v 1.30 2010/05/28 13:21:26 tsutsui Exp $
#

DISTNAME=	simhv38-1
PKGNAME=	simh-3.8.1
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's historical computer simulator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6

WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "arm")
BUILDLINK_TRANSFORM+=	rm:-O2
.endif

INSTALLATION_DIRS=	bin share/simh share/doc/simh

MAKE_FILE=		makefile
MAKE_FLAGS+=		USE_NETWORK=YES

post-extract:
	${MKDIR} ${WRKSRC}/BIN

do-install:
	(cd ${WRKSRC}/BIN && for BIN in *; do				\
		if [ -f $$BIN ] ; then					\
		${INSTALL_PROGRAM} $$BIN ${DESTDIR}${PREFIX}/bin/simh-$$BIN; \
		fi ;							\
	done)
	${INSTALL_DATA} ${WRKSRC}/VAX/ka655x.bin ${DESTDIR}${PREFIX}/share/simh
	(cd ${WRKSRC} && for TXT in *.txt */*.txt; do			\
		${INSTALL_DATA} $$TXT ${DESTDIR}${PREFIX}/share/doc/simh;		\
	done)

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
