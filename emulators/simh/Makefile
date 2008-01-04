# $NetBSD: Makefile,v 1.26 2008/01/04 21:45:05 joerg Exp $
#

DISTNAME=	simhv33-0
PKGNAME=	simh-3.3.0
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's historical computer simulator

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6

EXTRACT_OPTS_ZIP=	-aoq
WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "arm")
.if (${CFLAGS:M-O2} == "-O2")
CFLAGS:=	${CFLAGS:S/-O2//}
.endif
.endif

INSTALLATION_DIRS=	bin share/simh share/doc/simh

post-extract:
	${MKDIR} ${WRKSRC}/BIN
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC}/BIN && for BIN in *; do				\
		${INSTALL_PROGRAM} $$BIN ${DESTDIR}${PREFIX}/bin/simh-$$BIN;	\
	done)
	${INSTALL_DATA} ${WRKSRC}/VAX/ka655.bin ${DESTDIR}${PREFIX}/share/simh
	(cd ${WRKSRC} && for TXT in *.txt */*.txt; do			\
		${INSTALL_DATA} $$TXT ${DESTDIR}${PREFIX}/share/doc/simh;		\
	done)

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
