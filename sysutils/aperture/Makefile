# $NetBSD: Makefile,v 1.9 2001/01/17 23:57:52 jlam Exp $

DISTNAME=	apNetBSD
PKGNAME=	aperture-2.0nb1
CATEGORIES=	sysutils x11
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/xsrc/xfree/xc/programs/Xserver/hw/xfree86/etc/
EXTRACT_SUFX=	.shar

MAINTAINER=	jlam@netbsd.org

DIST_SUBDIR=	${PKGNAME}
NO_WRKSUBDIR=	# defined
NO_CONFIGURE=	# defined

EXTRACT_CMD=	${SH} ${DOWNLOADED_DISTFILE}
ALL_TARGET=	cleandir depend all
INSTALL_TARGET=	dirs includes install

OSVERSION_SPECIFIC=	# defined
ONLY_FOR_PLATFORM=	NetBSD-*-i386

BSDSRCDIR?=	/nonexistent	# to override <bsd.own.mk>, MUST be
                                # set this way BEFORE bsd.prefs.mk
.include "../../mk/bsd.prefs.mk"

pre-extract:
.if ${BSDSRCDIR} == "/nonexistent"
	@${ECHO_MSG} "Please set BSDSRCDIR in /etc/mk.conf, pointing it"
	@${ECHO_MSG} "to a directory that contains sources that match"
	@${ECHO_MSG} "your currently running system (esp. kernel), e.g."
	@${ECHO_MSG} "/usr/src."
	@${FALSE}
.endif
.if !exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
	@${ECHO_MSG} "Need a kernel source tree in ${BSDSRCDIR}/sys."
	@${ECHO_MSG} "(Or set BSDSRCDIR correctly in /etc/mk.conf.)"
	@${FALSE}
.endif

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# empty since we use BSD-style makefiles
