# $NetBSD: Makefile,v 1.117 2013/01/07 21:53:53 wiz Exp $

DISTNAME=	gnupg-1.4.13
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/ \
		http://gd.tuwien.ac.at/privacy/gnupg/gnupg/ \
		ftp://ftp.jyu.fi/pub/crypt/gcrypt/gnupg/ \
		ftp://ftp.ring.gr.jp/pub/net/gnupg/gnupg/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	GNU Privacy Guard, public-Key encryption and digital signatures
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CRYPTO=			yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
CONFIGURE_ARGS+=	--with-static-rnd=auto
CONFIGURE_ARGS+=	--with-mailprog=/usr/sbin/sendmail
TEST_TARGET=		check
INFO_FILES=		yes

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include "options.mk"

.if ${OPSYS} == "SunOS" || (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.[0-6]*))
CONFIGURE_ARGS+=	--disable-gnupg-iconv
.endif

.if (${OPSYS} == "AIX" || ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS") \
    && defined(ABI) && ${ABI} == 64
CONFIGURE_ARGS+=	--disable-asm
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/DETAILS \
	    ${DESTDIR}${PREFIX}/share/gnupg

.include "../../devel/readline/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
