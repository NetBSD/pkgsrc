# $NetBSD: Makefile,v 1.17 2022/05/18 00:28:02 charlotte Exp $

DISTNAME=		skalibs-2.11.2.0
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		charlotte@NetBSD.org
HOMEPAGE=		https://skarnet.org/software/skalibs/
COMMENT=		The skarnet.org C system programming library
LICENSE=		isc

USE_LANGUAGES=		c
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

# for fdopendir
CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

# from patch-for-solaris
SUBST_CLASSES.SunOS+=	solaris
SUBST_STAGE.solaris=	pre-configure
SUBST_FILES.solaris=	configure
SUBST_SED.solaris=	-e 's|XOPEN_SOURCE=700|XOPEN_SOURCE=600|g'

INSTALLATION_DIRS=	include/skalibs lib/skalibs/sysdeps

post-install:
	${LN} -sf ../libskarnet.a ${DESTDIR}${PREFIX}/lib/skalibs/libskarnet.a

.include "../../mk/bsd.pkg.mk"
