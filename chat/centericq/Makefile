# $NetBSD: Makefile,v 1.75.4.1 2012/04/08 09:18:54 sbd Exp $
#

DISTNAME=	centericq-4.21.0
PKGREVISION=	8
CATEGORIES=	chat
MASTER_SITES=	http://thekonst.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thekonst.net/eng/software/centericq/info.html
COMMENT=	Instant Messenger interface supporting many protocols

CONFLICTS=	centerim<4.22.5

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl --with-openssl=${SSLBASE:Q}
LIBS+=			${LDFLAGS}

REPLACE_PERL=		misc/cicqconv

INCOMPAT_CURSES+=	NetBSD-1.[45]*-* NetBSD-1.6-* NetBSD-1.6.[1-9]-*
INCOMPAT_CURSES+=	NetBSD-1.6_*-* NetBSD-1.6.[1-9]_*-* NetBSD-1.6[A-T]-*
INCOMPAT_CURSES+=	NetBSD-2.*-* NetBSD-3.*-*	# see PR 29060
INCOMPAT_CURSES+=	NetBSD-4.*-*

BROKEN=	Not compilable due to C++ language drift, and dead upstream.

NOT_FOR_PLATFORM+=	DragonFly-2.1[0-9]-* DragonFly-[3-9].*-*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=		-DAUDIO_PLAYER="\"/usr/bin/audioplay\""
.else
DEPENDS+=		sox>=12.17.4:../../audio/sox
EVAL_PREFIX+=		SOX_PREFIX=sox
CPPFLAGS+=		-DAUDIO_PLAYER="\"${SOX_PREFIX}/bin/play\""
.endif

.if !empty(MACHINE_ARCH:Msparc64)
GCC_REQD+=		3.0	# see PR 29185
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
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
	${INSTALL_MAN} ${WRKSRC}/centericq.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"

.if ${MACHINE_ARCH} == "alpha"
# avoid toolchain bugs
CFLAGS:=	${CFLAGS:C/-O[0-9]*//g}
.endif
