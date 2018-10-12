# $NetBSD: Makefile,v 1.35 2018/10/12 13:51:59 martin Exp $
#

DISTNAME=	id3lib-3.8.3
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=id3lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://id3lib.sourceforge.net/
COMMENT=	Library for manipulating ID3v1 and ID3v2 tags
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CPPFLAGS+=-DID3_NEED_WCHAR_TEMPLATE

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MSunOS-5.1[0-9]-*)
.  include "../../mk/compiler.mk"
.  if !empty(CC_VERSION:Mgcc-4.[6-9].*)
CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -std=c99
.  endif
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
