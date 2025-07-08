# $NetBSD: Makefile,v 1.30 2025/07/08 21:13:37 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		skalibs-2.14.4.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=skarnet/}
GITHUB_PROJECT=		skalibs
GITHUB_TAG=		5bc6d77b08b39f863a7d8767a588f839c19d3113

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/skalibs/
COMMENT=		The skarnet.org C system programming library
LICENSE=		isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-allstatic

# for fdopendir
CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

# from patch-for-solaris
SUBST_CLASSES.SunOS+=	solaris
SUBST_STAGE.solaris=	pre-configure
SUBST_FILES.solaris=	configure
SUBST_SED.solaris=	-e 's|XOPEN_SOURCE=700|XOPEN_SOURCE=600|g'

INSTALLATION_DIRS=	include/${PKGBASE} lib/${PKGBASE}/sysdeps

.include "shlibs.mk"

.include "../../mk/bsd.pkg.mk"
