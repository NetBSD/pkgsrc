# $NetBSD: Makefile,v 1.40 2004/10/03 00:13:13 tv Exp $
#

DISTNAME=	centericq-4.10.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://konst.org.ua/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://konst.org.ua/eng/software/centericq/info.html
COMMENT=	Instant Messenger interface for ICQ2000, Yahoo!, MSN and Jabber

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GCC_SHLIB=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl --with-openssl=${SSLBASE}
LIBS=			${LDFLAGS}

USE_PERL5=		run
REPLACE_PERL=		misc/cicqconv

INCOMPAT_CURSES+=	NetBSD-1.[45]*-* NetBSD-1.6-* NetBSD-1.6.[1-9]-*
INCOMPAT_CURSES+=	NetBSD-1.6_*-* NetBSD-1.6.[1-9]_*-* NetBSD-1.6[A-T]-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=		-DAUDIO_PLAYER=\"\\\"/usr/bin/audioplay\\\"\"
.else
DEPENDS+=		sox>=12.17.4:../../audio/sox
SOX_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		SOX_PREFIX=sox
CPPFLAGS+=		-DAUDIO_PLAYER=\"\\\"${SOX_PREFIX}/bin/play\\\"\"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.if defined(BUILDLINK_LIBICONV_LDADD) && !empty(BUILDLINK_LIBICONV_LDADD)
#
# libiconv depends on configure scripts to include <iconv.h> before
# trying to link against -liconv.  Unfortunately, centericq's script
# doesn't do this, so fake it.
#
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv=yes
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/centericq.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"

.if ${MACHINE_ARCH} == "alpha"
# avoid toolchain bugs
CFLAGS:=	${CFLAGS:C/-O[0-9]*//g}
.endif
