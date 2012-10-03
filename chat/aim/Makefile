# $NetBSD: Makefile,v 1.20 2012/10/03 00:02:33 asau Exp $

DISTNAME=	aim-1.5.286-1.i386
PKGNAME=	aim-1.5.286
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://ftp.newaol.com/aimgen/380469/
EXTRACT_SUFX=	.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.aim.com/
COMMENT=	AOL Instant Messenger (SM)

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat x11 gtk

.include "../../mk/bsd.prefs.mk"

# This package installs from an RPM directly into "/usr" on a Linux
# system, which can't be managed by pkgsrc unless ${LOCALBASE} == "/usr".
#
.if (${OPSYS} == "Linux") && (${LOCALBASE} != "/usr")
NOT_FOR_PLATFORMS=	Linux-*-*
.endif

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

EMUL_PKG_FMT=		rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
.if (${OPSYS} == "Linux") && (${LOCALBASE} == "/usr")
RPM2PKG_STRIP=		1
.else
RPM2PKG_STRIP=		0
.endif
RPM2PKG_STAGE=		do-install

INSTALLATION_DIRS=	bin

.if ${OPSYS} != "Linux"
post-install:
	${LN} -fs ${EMULDIR}/usr/bin/aim ${DESTDIR}${PREFIX}/bin/aim
	${ECHO} "bin/aim" >> ${RPM2PKG_PLIST}
.endif

.include "../../mk/bsd.pkg.mk"
