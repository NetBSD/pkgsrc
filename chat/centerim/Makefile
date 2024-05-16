# $NetBSD: Makefile,v 1.75 2024/05/16 06:14:36 wiz Exp $
#

DISTNAME=	centerim-4.22.10
PKGREVISION=	41
CATEGORIES=	chat
MASTER_SITES=	https://transacid.de/centerim/releases/



MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.centerim.org/
COMMENT=	Instant Messenger interface supporting many protocols
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl:run
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl --with-openssl=${SSLBASE:Q}
LIBS+=			${LDFLAGS}

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

REPLACE_PERL=		misc/cimextracthistory.pl
REPLACE_PERL+=		misc/cimconv
REPLACE_PYTHON+=	misc/CenterIMLog2HTML.py
REPLACE_AWK+=		misc/cimformathistory

INCOMPAT_CURSES+=	NetBSD-[0-5].*-* # see PR 29060

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=		-DAUDIO_PLAYER="\"/usr/bin/audioplay\""
.else
DEPENDS+=		sox>=12.17.4:../../audio/sox
CPPFLAGS+=		-DAUDIO_PLAYER="\"${LOCALBASE}/bin/play\""
.endif

# 1 safe instance in xmltok.c:1494
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../lang/python/application.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

.if defined(BUILDLINK_LIBICONV_LDADD) && !empty(BUILDLINK_LIBICONV_LDADD)
#
# libiconv depends on configure scripts to include <iconv.h> before
# trying to link against -liconv.  Unfortunately, centericq's script
# doesn't do this, so fake it.
#
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv=yes
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/centerim.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"

.if ${MACHINE_ARCH} == "alpha"
# avoid toolchain bugs
CFLAGS:=	${CFLAGS:C/-O[0-9]*//g}
.endif
