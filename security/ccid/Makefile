# $NetBSD: Makefile,v 1.48 2024/10/14 15:40:30 nia Exp $

DISTNAME=	ccid-1.6.1
CATEGORIES=	security
MASTER_SITES=	https://ccid.apdu.fr/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ccid.apdu.fr/
COMMENT=	Middleware to access a smart card using SCard API (PC/SC)
LICENSE=	gnu-lgpl-v2.1

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf flex perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

TOOL_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so
PLIST_SUBST+=		SOEXT=${SOEXT}
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=		OSNAME=MacOS
.elif ${OPSYS} == "SunOS"
PLIST_SUBST+=		OSNAME=Solaris
.else
PLIST_SUBST+=		OSNAME=${OPSYS}
.endif

# Work around a bug where the rules for parse do not include the
# PTHREAD vars.  Not yet reported upstream.
PTHREAD_AUTO_VARS=	yes

REPLACE_PERL=		src/convert_version.pl src/create_Info_plist.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	sbin share/doc/ccid

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	install_name_tool -id \
		${PREFIX}/lib/pcsc-lite/drivers/ifd-ccid.bundle/Contents/MacOS/libccid.dylib \
		${DESTDIR}${PREFIX}/lib/pcsc-lite/drivers/ifd-ccid.bundle/Contents/MacOS/libccid.dylib
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/ccid/README.md
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd \
	${DESTDIR}${PREFIX}/bin/RSA_SecurID_getpasswd
	${INSTALL_DATA} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/RSA_SecurID_getpasswd.1
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch \
	${DESTDIR}${PREFIX}/sbin/Kobil_mIDentity_switch
	${INSTALL_DATA} ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.8 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/Kobil_mIDentity_switch.8
	${INSTALL_DATA} ${WRKSRC}/contrib/Kobil_mIDentity_switch/README_Kobil_mIDentity_switch.txt \
	${DESTDIR}${PREFIX}/share/doc/ccid/README_Kobil_mIDentity_switch.txt

.include "../../security/pcsc-lite/buildlink3.mk"
.if ${OPSYS} == "Linux"
BUILDLINK_DEPMETHOD.flex=	full
.include "../../devel/flex/buildlink3.mk"
.endif
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
