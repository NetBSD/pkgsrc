# $NetBSD: Makefile,v 1.7 2012/10/03 21:57:23 wiz Exp $
#

DISTNAME=	ccid-1.3.11
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3080/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://pcsclite.alioth.debian.org/ccid.html
COMMENT=	Middleware to access a smart card using SCard API (PC/SC)

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	autoconf automake aclocal autoheader
USE_TOOLS+=	flex perl
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=        --sharedstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_FILES.perl=	src/convert_version.pl src/create_Info_plist.pl
SUBST_SED.perl=		-e 's,/usr/bin/perl,${PERL5},'

pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap

post-install:
	 ${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ccid/README

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
