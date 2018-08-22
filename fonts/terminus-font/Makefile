# $NetBSD: Makefile,v 1.20 2018/08/22 09:45:07 wiz Exp $

DISTNAME=		terminus-font-4.40
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=terminus-font/}

MAINTAINER=		j+pkgsrc@salmi.ch
HOMEPAGE=		http://terminus-font.sourceforge.net/
COMMENT=		Clean, fixed-width font
LICENSE=		ofl-v1.1

USE_TOOLS+=		bdftopcf gmake gzip perl
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${PREFIX}/share/fonts/X11/misc

BUILD_TARGET=		pcf
INSTALL_TARGET=		install-pcf

FONTS_DIRS.x11=		${PREFIX}/share/fonts/X11/misc
REQD_DIRS+=		${PREFIX}/share/fonts/X11/misc

USE_LANGUAGES=		# none

EGDIR=		${PREFIX}/share/examples/terminus-font

DOCDIR=		${PREFIX}/share/doc/terminus-font
DOCFILES=	AUTHORS CHANGES OFL.TXT README README-BG

FCCONFDIR=	${PKG_SYSCONFDIR}/fontconfig/conf.d
MAKE_DIRS+=	${FCCONFDIR}

CONF_FILES=	${EGDIR}/75-yes-terminus.conf \
		${FCCONFDIR}/75-yes-terminus.conf

AUTO_MKDIRS=	yes

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_DATA} ${DOCFILES} ${DESTDIR}${DOCDIR}; \
	${INSTALL_DATA} 75-yes-terminus.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
