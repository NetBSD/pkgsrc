# $NetBSD: Makefile,v 1.39 2013/10/24 10:31:02 wiz Exp $

DISTNAME=	apNetBSD
PKGNAME=	aperture-2.0
PKGREVISION=	7
CATEGORIES=	sysutils x11
EXTRACT_SUFX=	.shar
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}nb1/}
# The definitive location of the distfile is as below, but it's risky to depend
# on NetBSD-current files to stay stable, so don't we'll place new copies at
# MASTER_SITE_LOCAL and update this package accordingly.
#
#MASTER_SITES+=	ftp://ftp.NetBSD.org/pub/NetBSD/NetBSD-current/xsrc/xfree/xc/programs/Xserver/hw/xfree86/etc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	XFree86 Framebuffer "aperture" driver for NetBSD/i386

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

PKG_DESTDIR_SUPPORT=	none
BROKEN=			Does not support DESTDIR; will be removed after 2013Q4

WRKSRC=			${WRKDIR}
BUILD_TARGET=		cleandir depend all
DIST_SUBDIR=		${PKGNAME_NOREV}nb5
INSTALL_TARGET=		dirs includes install
MANCOMPRESSED_IF_MANZ=	YES
NO_CONFIGURE=		YES
OSVERSION_SPECIFIC=	YES
MAKE_ENV+=		BSDSRCDIR=${BSDSRCDIR:Q}

.include "../../mk/bsd.prefs.mk"

pre-extract:
.if !exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
	@${ECHO_MSG} "Need a kernel source tree in ${BSDSRCDIR}/sys."
	@${ECHO_MSG} "(Or set BSDSRCDIR correctly in /etc/mk.conf.)"
	@${FALSE}
.endif

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# empty since we use BSD-style makefiles
