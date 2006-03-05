# $NetBSD: Makefile,v 1.4 2006/03/05 20:12:30 minskim Exp $
#

DISTNAME=	gnustep-objc-lf2.95.3-r88
PKGNAME=	${DISTNAME:S/.9/-2.9/:S/-r/./}
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.opengroupware.org/sources/releases/		\
		http://download.opengroupware.org/nightly/sources/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sope.opengroupware.org/en/build/thirdparty.html\#gstep_objc
COMMENT=	Objective-C library required for libFoundation

WRKSRC=		${WRKDIR}/libobjc-lf2
USE_TOOLS+=	gmake

do-configure:
	${MKDIR} ${WRKSRC}/config/${GNUSTEP_HOST_CPU}
	[ -e ${WRKSRC}/config/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS} ] || \
	${LN} -s linux-gnu ${WRKSRC}/config/${GNUSTEP_HOST_CPU}/generic

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
