# $NetBSD: Makefile,v 1.9 2002/11/25 14:07:42 schmonz Exp $
#

BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1
COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

.if ${MACHINE_ARCH} == "arm"
DISTNAME=	${BASENAME}-RC1-linux-arm
.endif

.include "../../lang/blackdown-jre13/Makefile.common"

ONLY_FOR_PLATFORM+=	NetBSD-*-arm Linux-*-arm

PLIST_SRC=	${PKGDIR}/PLIST
.if ${BLACKDOWN_ARCH} == "i386"
PLIST_SRC+=	${PKGDIR}/PLIST.i386
.endif

.include "../../mk/bsd.pkg.mk"

PREFIX=		${JVM_HOME}
