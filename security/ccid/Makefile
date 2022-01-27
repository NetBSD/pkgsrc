# $NetBSD: Makefile,v 1.39 2022/01/27 13:21:20 gdt Exp $
#

DISTNAME=	ccid-1.5.0
CATEGORIES=	security
MASTER_SITES=	https://ccid.apdu.fr/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://ccid.apdu.fr/
COMMENT=	Middleware to access a smart card using SCard API (PC/SC)
LICENSE=	gnu-lgpl-v2.1

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS=	VARBASE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	flex perl
USE_LANGUAGES=	c c++

# Work around a bug where the rules for parse do not include the
# PTHREAD vars.  Not yet reported upstream.
PTHREAD_AUTO_VARS=	yes

CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

REPLACE_PERL=		src/convert_version.pl src/create_Info_plist.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	sbin share/doc/ccid

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
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
