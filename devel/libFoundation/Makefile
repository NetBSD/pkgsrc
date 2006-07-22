# $NetBSD: Makefile,v 1.10 2006/07/22 05:10:54 rillig Exp $
#

DISTNAME=	libFoundation-1.0.72-r107
PKGNAME=	${DISTNAME:S/-r/./}
PKGREVISION=	2
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.opengroupware.org/sources/releases/		\
		http://www.opengroupware.org/sources/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opengroupware.org/en/devs/thirdparty/libFoundation/
COMMENT=	Library implementing the OpenStep Foundation API

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/libfoundation

GNU_CONFIGURE=	yes
MAKE_ENV+=	ADDITIONAL_OBJCFLAGS="-I${WRKSRC} -I."
MAKE_ENV+=	FOUNDATION_LIB="fd"
MAKE_ENV+=	INSTALL_DATA=${INSTALL_DATA:Q}

PLIST_SUBST+=	GNUSTEP_HOST_CPU=${GNUSTEP_HOST_CPU:Q}
PLIST_SUBST+=	LIBF_HOST_OS=${LIBF_HOST_OS}

LIBF_HOST_OS=	${GNUSTEP_HOST:C/.*-//}

.include "../../devel/gnustep-objc-lf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

pre-configure:
	${MKDIR} ${WRKSRC}/config/${MACHINE_GNU_ARCH}
	[ -e ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${GNUSTEP_HOST_OS}.h ] || \
	${LN} -s linux.h ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${GNUSTEP_HOST_OS}.h
.if ${GNUSTEP_HOST_OS} != ${LIBF_HOST_OS}
	[ -e ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${LIBF_HOST_OS}.h ] || \
	${LN} -s linux.h ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${LIBF_HOST_OS}.h
.endif

post-configure:
	-${MKDIR} ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}
	[ -e ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}/${LIBF_HOST_OS} ] || \
	  ${LN} -s							\
	    ${WRKSRC}/Foundation/${LIBF_HOST_OS}	\
	    ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}/${LIBF_HOST_OS}

.include "../../mk/bsd.pkg.mk"
