# $NetBSD: Makefile,v 1.1.1.1 2005/12/31 22:42:31 markd Exp $
#

DISTNAME=		gwydion-dylan-${DYLAN_VERSION}
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.gwydiondylan.org/pub/gd/src/tar/ \
			ftp://ftp.fu-berlin.de/pub/unix/languages/dylan/src/tar/ \
			ftp://ftp.ntua.gr/pub/lang/gwydion/src/tar/ \
			ftp://gd.tuwien.ac.at/languages/gwydiondylan/src/tar/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gwydiondylan.org/
COMMENT=		Functional language

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
MAKEFILE=		GNUmakefile
BUILD_TARGET=		default

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-mindy-bootstrap

DYLAN_VERSION=		2.4.0

# other architecture changes will be gratefully received
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-sparc NetBSD-*-powerpc

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
ALT_ARCH=		x86
.elif ${MACHINE_ARCH} == "powerpc"
ALT_ARCH=		ppc
.else
ALT_ARCH=		${MACHINE_ARCH}
.endif

PLIST_SUBST+=		ALT_ARCH=${ALT_ARCH:Q}
PLIST_SUBST+=		DYLAN_VERSION=${DYLAN_VERSION:Q}

.include "../../devel/boehm-gc/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
