# $NetBSD: Makefile,v 1.20 2002/09/13 07:18:42 tron Exp $

DISTNAME=	apNetBSD
PKGNAME=	aperture-2.0
PKGREVISION=	1
CATEGORIES=	sysutils x11
EXTRACT_SUFX=	.shar

# Not sure why ${MASTER_SITE_LOCAL:=${PKGNAME}} doesn't work, but the
# following does the correct substitution.
#
.for subdir in ${PKGNAME}
MASTER_SITES=	${MASTER_SITE_LOCAL:=${subdir}nb1/}
.endfor

# The definitive location of the distfile is as below, but it's risky to depend
# on NetBSD-current files to stay stable, so don't we'll place new copies at
# MASTER_SITE_LOCAL and update this package accordingly.
#
#MASTER_SITES+=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-current/xsrc/xfree/xc/programs/Xserver/hw/xfree86/etc/

MAINTAINER=	jlam@netbsd.org
COMMENT=	XFree86 Framebuffer "aperture" driver for NetBSD/i386

ONLY_FOR_PLATFORM=	NetBSD-1.[0-5]*-i386 NetBSD-1.6-i386 \
			NetBSD-1.6.*-i386 NetBSD-1.6[A-G]-i36

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

ALL_TARGET=		cleandir depend all
DIST_SUBDIR=		${PKGNAME}
INSTALL_TARGET=		dirs includes install
MANCOMPRESSED_IF_MANZ=	YES
WRKSRC=			${WRKDIR}
NO_CONFIGURE=		YES
OSVERSION_SPECIFIC=	YES

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
