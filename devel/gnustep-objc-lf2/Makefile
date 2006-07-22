# $NetBSD: Makefile,v 1.7 2006/07/22 05:10:54 rillig Exp $
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

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/libobjc-lf2
USE_TOOLS+=	gmake

.include "../../devel/gnustep-make/buildlink3.mk"

do-configure:
.if ${GNUSTEP_HOST_CPU} == "x86_64"
	${LN} -s alpha ${WRKSRC}/config/x86_64
.else
	${MKDIR} ${WRKSRC}/config/${GNUSTEP_HOST_CPU}
	[ -e ${WRKSRC}/config/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS} ] || \
	${LN} -s linux-gnu ${WRKSRC}/config/${GNUSTEP_HOST_CPU}/generic
.endif

.include "../../mk/bsd.pkg.mk"
