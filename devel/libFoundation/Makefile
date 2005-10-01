# $NetBSD: Makefile,v 1.3 2005/10/01 04:25:32 rh Exp $
#

DISTNAME=	libFoundation-1.0.72-r107
PKGNAME=	${DISTNAME:S/-r/./}
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.opengroupware.org/sources/releases/		\
		http://www.opengroupware.org/sources/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.opengroupware.org/en/devs/thirdparty/libFoundation/
COMMENT=	Library implementing the OpenStep Foundation API

WRKSRC=		${WRKDIR}/libfoundation

GNU_CONFIGURE=	yes
MAKE_ENV+=	ADDITIONAL_OBJCFLAGS="-I${WRKSRC} -I."
MAKE_ENV+=	FOUNDATION_LIB="fd"
MAKE_ENV+=	INSTALL_DATA=${INSTALL_DATA:Q}

PLIST_SUBST+=	GNUSTEP_HOST_CPU=${GNUSTEP_HOST_CPU}

LIBF_HOST_OS=	${GNUSTEP_HOST:C/.*-//}

pre-configure:
	${MKDIR} ${WRKSRC}/config/${MACHINE_GNU_ARCH}
	[ -e ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${GNUSTEP_HOST_OS}.h ] || \
	${LN} -s linux.h ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${GNUSTEP_HOST_OS}.h
	[ -e ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${LIBF_HOST_OS}.h ] || \
	${LN} -s linux.h ${WRKSRC}/config/${MACHINE_GNU_ARCH}/${LIBF_HOST_OS}.h

post-configure:
	-${MKDIR} ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}
	[ -e ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}/${GNUSTEP_HOST_OS} ] || \
	  ${LN} -s							\
	    ${WRKSRC}/Foundation/${LIBF_HOST_OS}	\
	    ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}/${GNUSTEP_HOST_OS}

.include "../../devel/gnustep-objc-lf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
