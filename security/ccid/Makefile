# $NetBSD: Makefile,v 1.26 2018/08/22 09:46:17 wiz Exp $
#

DISTNAME=	ccid-1.4.26
PKGREVISION=	2
CATEGORIES=	security
# Note that the MASTER_SITES URL is not stable with version changes,
# and one can end up with an old version if DISTNAME is changed but
# not the magic number in MASTER_SITES.
# https://alioth.debian.org/frs/?group_id=30105#title_ccid
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/4205/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://pcsclite.alioth.debian.org/ccid.html
COMMENT=	Middleware to access a smart card using SCard API (PC/SC)
LICENSE=	gnu-lgpl-v2.1

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS=	VARBASE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	autoconf automake aclocal autoheader
USE_TOOLS+=	flex perl
USE_LANGUAGES=	c c++

# Work around a bug where the rules for parse do not include the
# PTHREAD vars.  Not yet reported upstream.
PTHREAD_AUTO_VARS=	yes

CONFIGURE_ARGS+=        --sharedstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR:Q}

REPLACE_PERL=		src/convert_version.pl src/create_Info_plist.pl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	sbin share/doc/ccid

pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ccid/README
	${INSTALL_DATA} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd \
	${DESTDIR}${PREFIX}/bin/RSA_SecurID_getpasswd
	${INSTALL_DATA} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd.1 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/RSA_SecurID_getpasswd.1
	${INSTALL_DATA} ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch \
	${DESTDIR}${PREFIX}/sbin/Kobil_mIDentity_switch
	${INSTALL_DATA} ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.8 \
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/Kobil_mIDentity_switch.8
	${INSTALL_DATA} ${WRKSRC}/contrib/Kobil_mIDentity_switch/README_Kobil_mIDentity_switch.txt \
	${DESTDIR}${PREFIX}/share/doc/ccid/README_Kobil_mIDentity_switch.txt

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
