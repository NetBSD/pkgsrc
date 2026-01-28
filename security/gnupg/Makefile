# $NetBSD: Makefile,v 1.177 2026/01/28 09:28:12 wiz Exp $

DISTNAME=	gnupg-1.4.23
PKGREVISION=	28
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG:=gnupg/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnupg.org/
COMMENT=	GNU Privacy Guard, public-Key encryption and digital signatures (old 1.x branch)
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
CONFIGURE_ARGS+=	--with-mailprog=/usr/sbin/sendmail
TEST_TARGET=		check
INFO_FILES=		yes
CONFIGURE_ARGS+=	--program-suffix=1

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include "options.mk"

CONFIGURE_ARGS.SunOS+=	--disable-gnupg-iconv

.if (${OPSYS} == "AIX" || ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS") \
    && defined(ABI) && ${ABI} == 64
CONFIGURE_ARGS+=	--disable-asm
.endif

.if ${MACHINE_ARCH} == "i386" && ${PKGSRC_MKPIE:tl} == "yes"
CONFIGURE_ARGS+=	--disable-asm
.endif

.if ${USE_CROSS_COMPILE:U:tl} == yes
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/DETAILS \
	    ${DESTDIR}${PREFIX}/share/gnupg
	${MV} ${DESTDIR}${PREFIX}/share/gnupg \
	    ${DESTDIR}${PREFIX}/share/gnupg1

.include "../../devel/readline/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
