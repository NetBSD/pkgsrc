# $NetBSD: Makefile,v 1.35 2012/03/03 00:12:11 wiz Exp $
#

DISTNAME=		enchant-1.6.0
PKGREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		http://www.abisource.com/downloads/enchant/1.6.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.abisource.com/projects/enchant/
COMMENT=		Generic spell checking library
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config autoconf
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

CONFIGURE_ARGS+=	--with-myspell-dir=${BUILDLINK_PREFIX.hunspell}/share/hunspell

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
