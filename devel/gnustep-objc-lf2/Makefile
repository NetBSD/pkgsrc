# $NetBSD: Makefile,v 1.1.1.1 2005/10/01 04:18:47 rh Exp $
#

DISTNAME=	gnustep-objc-lf2.95.3-r88
PKGNAME=	${DISTNAME:S/.9/-2.9/:S/-r/./}
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.opengroupware.org/sources/releases/		\
		http://download.opengroupware.org/nightly/sources/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sope.opengroupware.org/en/build/thirdparty.html\#gstep_objc
COMMENT=	Objective-C library required for libFoundation

WRKSRC=		${WRKDIR}/libobjc-lf2
USE_TOOLS+=	gmake

do-configure:
	${MKDIR} ${WRKSRC}/config/${GNUSTEP_HOST_CPU}
	[ -e ${WRKSRC}/config/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS} ] || \
	${LN} -s linux-gnu ${WRKSRC}/config/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
