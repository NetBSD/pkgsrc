# $NetBSD: Makefile,v 1.15 2001/06/26 03:29:17 jlam Exp $
#

DISTNAME=	SDL-1.2.0
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
BUILDLINK_DEPENDS.pth=	pth>=1.4.0

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
#USE_MESA=		YES
USE_X11=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
NASMFLAGS=		-f elf
.else
NASMFLAGS=		-f aoutb
.endif

.ifdef SDL_USE_NAS
.include "../../audio/nas/buildlink.mk"
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

CONFIGURE_ARGS+=	--disable-pthread-sem
CONFIGURE_ENV+=		NASMFLAGS="${NASMFLAGS}"
MAKE_ENV+=		NASMFLAGS="${NASMFLAGS}"

pre-patch:
	cd ${WRKSRC} && ${MKDIR} src/audio/netbsd

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf --force

post-configure:
	cd ${WRKSRC}/src/audio && ${CP} *.[ch] netbsd/

# Fix config scripts by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	config_scripts="sdl-config";					\
	for file in $${config_scripts}; do				\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
			-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

.include "../../audio/esound/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
