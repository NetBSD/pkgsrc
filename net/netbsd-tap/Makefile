# $NetBSD: Makefile,v 1.5 2005/06/10 15:06:33 cube Exp $

# This package relies on a correct configuration of pkgsrc WRT NetBSD
# source directory information, otherwise the build will fail in a non-
# obvious way.
#
# If /usr/src doesn't point to your NetBSD source tree, then you should
# (generally speaking, it covers more than pkgsrc) define the variable
# named NETBSDSRCDIR to the place where that NetBSD source tree is.
#
# Setting NETBSDSRCDIR in mk.conf will do the right thing when, for
# example, you compile a LKM by hand.  However, it will not be
# sufficient in pkgsrc, as the Makefiles of the packages are called
# with MAKECONF=/dev/null in the environment by default, and therefore
# won't pick up the value for NETBSDSRCDIR.
#
# So additionally you will have to define PKGMAKECONF in mk.conf, and
# make it point to a mk.conf-like file that will contain your wished
# NETBSDSRCDIR, COPTS, CPUFLAGS and friends value.
#
# It is perfectly acceptable to set PKGMAKECONF to /etc/mk.conf, but be
# aware that it can lead to some confusion of pkgsrc, which is why
# MAKECONF was set to /dev/null in the first place.

DISTNAME=	netbsd-tap-20050610
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cube@NetBSD.org
COMMENT=	NetBSD kernel module for virtual Ethernet devices

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
INSTALL_TARGET=	includes install

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*
INSTALLATION_DIRS=	lkm

.include "options.mk"

SUBST_CLASSES+=	tap_postinstall
SUBST_STAGE.tap_postinstall=	post-build
SUBST_FILES.tap_postinstall=	tap_postinstall.sh
SUBST_SED.tap_postinstall=	-e s,@SH@,${SH:Q},

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
