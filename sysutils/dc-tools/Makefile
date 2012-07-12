# $NetBSD: Makefile,v 1.1.1.1 2012/07/12 23:55:55 abs Exp $

DISTNAME=	dc-tools-1.00
CATEGORIES=	sysutils
MASTER_SITES=	http://mc.pp.se/dc/files/ \
		https://github.com/abs0/dc-burn-netbsd/tarball/1.0
DIST_SUBDIR=	dc-tools
DISTFILES=	makeip.tar.gz scramble.c ip_slave.tar.gz serial_slave.tar.gz \
		${DCBURN_DISTFILE}
DCBURN_DISTFILE=abs0-dc-burn-netbsd-1.0-0-gf333dc8

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://mc.pp.se/dc/sw.html
COMMENT=	Marcus Comstedt's tools for generating Dreamcast bootable CDs
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

FETCH_USING=	curl	# For github

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
SUBST_MESSAGE.conf=	Update path to IP.TMPL

DCBURN_WRKSRC=${DCBURN_DISTFILE:C:-[0-9].*-0-g:-:}
WRKSRC=${WRKDIR}

USE_TOOLS+=	tar

INSTALLATION_DIRS=bin share/dc-tools/serial_slave share/dc-tools/ip_slave share/doc

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

.include "../../mk/bsd.pkg.mk"
