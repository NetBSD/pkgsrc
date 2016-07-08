# $NetBSD: Makefile,v 1.13 2016/07/08 08:30:30 abs Exp $

DISTNAME=	dc-tools-1.6
CATEGORIES=	sysutils
MASTER_SITES=	http://mc.pp.se/dc/files/ \
		https://github.com/abs0/dc-burn-netbsd/archive/
DIST_SUBDIR=	dc-tools
DISTFILES=	makeip.tar.gz scramble.c ip_slave.tar.gz serial_slave.tar.gz \
		${DCBURN_DISTFILE}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://mc.pp.se/dc/sw.html
COMMENT=	Dreamcast bootable CDs tools (mainly from Marcus Comstedt)
#LICENSE=	# TODO: (see mk/license.mk)

DCBURN_TAG=	1.6
DCBURN_DISTFILE=${DCBURN_TAG}.tar.gz

DEPENDS+=	cdrtools>=2.01:../../sysutils/cdrtools

# The filenames in the _slave.tar.gz files overlap
EXTRACT_CMD=	${CP} ${DISTDIR}/${DIST_SUBDIR}/scramble.c ${WRKSRC} && \
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/makeip.tar.gz && \
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${DCBURN_DISTFILE} && \
	mkdir ip && \
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/ip_slave.tar.gz -C ip && \
	mkdir serial && \
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/serial_slave.tar.gz -C serial

SUBST_CLASSES+=		IP_TMPL
SUBST_STAGE.IP_TMPL=	post-patch
SUBST_FILES.IP_TMPL=	makeip.c
SUBST_SED.IP_TMPL=	-e "s|"IP.TMPL"|"${PREFIX}/share/dc-tools/IP.TMPL"|"
SUBST_MESSAGE.IP_TMPL=	Update path to IP.TMPL

DCBURN_WRKSRC=		dc-burn-netbsd-${DCBURN_TAG}
WRKSRC=			${WRKDIR}

USE_TOOLS+=		tar

INSTALLATION_DIRS=	bin share/dc-tools/serial_slave share/dc-tools/ip_slave share/doc

RESTRICTED=		makeip contains PRODUCED BY OR UNDER LICENSE FROM SEGA ENTERPRISES, LTD data
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o dc-makeip makeip.c
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o dc-scramble scramble.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dc-makeip ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dc-scramble ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${DCBURN_WRKSRC}/dc-burn-netbsd \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} DESCR ${DESTDIR}${PREFIX}/share/doc/dc-tools.README
	${INSTALL_DATA} ${WRKSRC}/IP.TMPL ${DESTDIR}${PREFIX}/share/dc-tools
	${INSTALL_DATA} ${WRKSRC}/ip.txt ${DESTDIR}${PREFIX}/share/dc-tools
	${INSTALL_DATA} ${WRKSRC}/ip/IP.BIN \
		${DESTDIR}${PREFIX}/share/dc-tools/ip_slave
	${INSTALL_DATA} ${WRKSRC}/ip/1IPLOAD.BIN \
		${DESTDIR}${PREFIX}/share/dc-tools/ip_slave
	${INSTALL_DATA} ${WRKSRC}/serial/IP.BIN \
		${DESTDIR}${PREFIX}/share/dc-tools/serial_slave

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
