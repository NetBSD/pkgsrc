# $NetBSD: Makefile,v 1.11 2001/05/05 14:32:43 jlam Exp $

DISTNAME=	apNetBSD
PKGNAME=	aperture-2.0nb1
CATEGORIES=	sysutils x11
EXTRACT_SUFX=	.shar

# Not sure why ${MASTER_SITE_LOCAL:=${PKGNAME}} doesn't work, but the
# following does the correct substitution.
#
.for subdir in ${PKGNAME}
MASTER_SITES=	${MASTER_SITE_LOCAL:=${subdir}/}
.endfor

# The definitive location of the distfile is as below, but it's risky to depend
# on NetBSD-current files to stay stable, so don't we'll place new copies at
# MASTER_SITE_LOCAL and update this package accordingly.
#
#MASTER_SITES+=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/xsrc/xfree/xc/programs/Xserver/hw/xfree86/etc/

MAINTAINER=	jlam@netbsd.org
COMMENT=	XFree86 Framebuffer "aperture" driver for NetBSD/i386

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
