# $NetBSD: Makefile,v 1.30 2003/09/27 17:07:35 grant Exp $
#

DISTNAME=	centericq-4.9.6
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://konst.org.ua/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://konst.org.ua/eng/software/centericq/info.html
COMMENT=	Instant Messenger interface for ICQ2000, Yahoo!, MSN and Jabber

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GCC_SHLIB=		yes
USE_GMAKE=		yes
USE_NCURSES=		yes

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

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/curses.buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.if defined(BUILDLINK_LIBICONV_LDADD) && !empty(BUILDLINK_LIBICONV_LDADD)
#
# libiconv depends on configure scripts to include <iconv.h> before
# trying to link against -liconv.  Unfortunately, centericq's script
# doesn't do this, so fake it.
#
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv=yes
.endif

.include "../../mk/bsd.pkg.mk"

.if ${MACHINE_ARCH} == "alpha"
# avoid toolchain bugs
CFLAGS:=	${CFLAGS:C/-O[0-9]*//g}
.endif
