# $NetBSD: Makefile,v 1.1.1.1 2008/11/21 17:40:29 adam Exp $

DISTNAME=	wine-1.1.8
CATEGORIES=	emulators
MASTER_SITES=	http://ibiblio.org/pub/linux/system/emulators/wine/ \
		${MASTER_SITE_SOURCEFORGE:=wine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.com/
COMMENT=	Free implementation of Windows on Unix

BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

#ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
#ONLY_FOR_PLATFORM+=	FreeBSD-*-i386 Linux-*-i386 SunOS-*-i386 Darwin-*-i386
#ONLY_FOR_PLATFORM+=	*-*-x86_64

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		bison flex gmake mktemp
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES=	datasize

REPLACE_PERL+=		tools/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
#
CONFIGURE_ENV+=		X_LIBS=${LDFLAGS:M*:Q}
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:Q}\ -DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
LIBS+=			${LDFLAGS}

.include "options.mk"

post-install:
.for tool in fnt2bdf
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/tools/${tool} \
		${DESTDIR}${PREFIX}/bin
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
