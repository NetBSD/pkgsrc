# $NetBSD: Makefile,v 1.25 2008/04/17 21:07:18 wiz Exp $
#

DISTNAME=		enchant-1.4.0
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		http://www.abisource.com/downloads/enchant/1.4.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.abisource.com/projects/enchant/
COMMENT=		Generic spell checking library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config autoconf
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

CONFIGURE_ARGS+=	--with-myspell-dir=${BUILDLINK_PREFIX.hunspell}/share/hunspell

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
