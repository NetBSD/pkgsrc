# $NetBSD: Makefile,v 1.1.1.1 2000/01/05 18:02:18 jlam Exp $

DISTNAME=	apNetBSD
PKGNAME=	aperture-2.0
CATEGORIES=	sysutils x11
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/xsrc/xc/programs/Xserver/hw/xfree86/etc/
EXTRACT_SUFX=	.shar

MAINTAINER=	packages@netbsd.org

EXTRACT_CMD=	${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
ALL_TARGET=	cleandir depend all
INSTALL_TARGET=	dirs includes install
NO_WRKSUBDIR=	yes
NO_CONFIGURE=	yes

ONLY_FOR_PLATFORM=	NetBSD-*-i386

.BEGIN:
	@if [ ! -f /sys/lib/libkern/libkern.h ]; then \
	    ${ECHO_MSG} "==================================================="; \
	    ${ECHO_MSG} "    Kernel sources are required to build LKMs."; \
	    ${ECHO_MSG} "    Please fetch them and make a link from /sys";  \
	    ${ECHO_MSG} "    to the kernel source directory (typically"; \
	    ${ECHO_MSG} "    /usr/src/sys)."; \
	    ${ECHO_MSG}; \
	    ${ECHO_MSG} "    Information for fetching kernel sources may be"; \
	    ${ECHO_MSG} "    found at the following URL:"; \
	    ${ECHO_MSG}; \
	    ${ECHO_MSG} "    http://www.netbsd.org/Documentation/"; \
	    ${ECHO_MSG} "==================================================="; \
	    ${FALSE}; \
	fi

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# empty since we use BSD-style makefiles

