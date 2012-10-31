# $NetBSD: common.mk,v 1.3 2012/10/31 11:17:10 asau Exp $
#

USE_LANGUAGES=		objc

WRKSRC=			${WRKDIR}/libfoundation

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
MAKE_ENV+=		ADDITIONAL_OBJCFLAGS="-I${WRKSRC} -I."
MAKE_ENV+=		FOUNDATION_LIB="fd"
MAKE_ENV+=		INSTALL_DATA=${INSTALL_DATA:Q}

LIBF_HOST_OS=	${GNUSTEP_HOST:C/.*-//}

FIX_GNUSTEP_INSTALLATION_DIR=	yes

.include "../../devel/gnustep-make/gnustep.mk"

PLIST_SUBST+=	GNUSTEP_HOST_CPU=${GNUSTEP_HOST_CPU:Q}
PLIST_SUBST+=	LIBF_HOST_OS=${LIBF_HOST_OS}

pre-configure:
	${MKDIR} ${WRKSRC}/config/${MACHINE_GNU_ARCH}
	[ -e ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${GNUSTEP_HOST_OS}.h ] || \
	${LN} -s linux.h ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${GNUSTEP_HOST_OS}.h
.if ${GNUSTEP_HOST_OS} != ${LIBF_HOST_OS}
	[ -e ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${LIBF_HOST_OS}.h ] || \
	${LN} -s linux.h ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${LIBF_HOST_OS}.h
.endif
