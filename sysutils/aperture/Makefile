# $NetBSD: Makefile,v 1.31 2004/04/24 22:46:11 jlam Exp $

DISTNAME=	apNetBSD
PKGNAME=	aperture-2.0
PKGREVISION=	5
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
#MASTER_SITES+=	ftp://ftp.NetBSD.org/pub/NetBSD/NetBSD-current/xsrc/xfree/xc/programs/Xserver/hw/xfree86/etc/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	XFree86 Framebuffer "aperture" driver for NetBSD/i386

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

WRKSRC=			${WRKDIR}
ALL_TARGET=		cleandir depend all
DIST_SUBDIR=		${PKGNAME}
INSTALL_TARGET=		dirs includes install
MANCOMPRESSED_IF_MANZ=	YES
NO_CONFIGURE=		YES
OSVERSION_SPECIFIC=	YES
MAKE_ENV+=		BSDSRCDIR="${BSDSRCDIR}"

.include "../../mk/bsd.prefs.mk"

pre-extract:
.if !exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
	@${ECHO_MSG} "Need a kernel source tree in ${BSDSRCDIR}/sys."
	@${ECHO_MSG} "(Or set BSDSRCDIR correctly in /etc/mk.conf.)"
	@${FALSE}
.endif

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# empty since we use BSD-style makefiles
