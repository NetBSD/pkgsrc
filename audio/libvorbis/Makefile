# $NetBSD: Makefile,v 1.12 2001/12/29 16:53:34 abs Exp $

DISTNAME=	libvorbis-1.0rc2
PKGNAME=	libvorbis-1.0.0.6
CATEGORIES=	devel audio
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.xiph.org/ogg/vorbis/
COMMENT=	Library for the Ogg Vorbis audio encoding format

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ogg-prefix=${BUILDLINK_DIR}

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PLIST_SUBST+=		DISTNAME=${DISTNAME}

.if (${MACHINE_ARCH} == "arm32")
ARM32_COMPILER_WORKAROUND!=gcc -v 2>&1 | awk '/egcs-2.91.66/{print $$3}'
.ifdef ${ARM32_COMPILER_WORKAROUND}
post-configure:
	printf '\nfloor1.lo:\n\t$$(LIBTOOL) --mode=compile $$(COMPILE) -O0 -c $$<\n\n' >> ${WRKSRC}/lib/Makefile
.endif
.endif

.include "../../audio/libogg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
