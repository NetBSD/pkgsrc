# $NetBSD: Makefile,v 1.28 2025/05/13 03:42:25 schmonz Exp $

DISTNAME=		skalibs-2.14.4.0
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/skalibs/
COMMENT=		The skarnet.org C system programming library
LICENSE=		isc

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig

# for fdopendir
CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

# from patch-for-solaris
SUBST_CLASSES.SunOS+=	solaris
SUBST_STAGE.solaris=	pre-configure
SUBST_FILES.solaris=	configure
SUBST_SED.solaris=	-e 's|XOPEN_SOURCE=700|XOPEN_SOURCE=600|g'

INSTALLATION_DIRS=	include/${PKGBASE} lib/${PKGBASE}/sysdeps

.include "../../mk/bsd.pkg.mk"
