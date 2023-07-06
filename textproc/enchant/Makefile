# $NetBSD: Makefile,v 1.45 2023/07/06 07:24:26 nia Exp $
#

DISTNAME=		enchant-1.6.0
PKGREVISION=		10
CATEGORIES=		textproc
MASTER_SITES=		http://www.abisource.com/downloads/enchant/1.6.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.abisource.com/projects/enchant/
COMMENT=		Generic spell checking library
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config autoconf
USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

INSTALLATION_DIRS+=	share/examples
MAKE_DIRS+=		${PREFIX}/share/enchant
CONF_FILES=		${PREFIX}/share/examples/enchant-1.ordering ${PREFIX}/share/enchant/enchant.ordering

# Unsupported in pkgsrc:
# hspell - Hebrew spelling
# uspell - Yiddish spelling
# voikko - Finnish spelling
#
# hunspell or aspell can be used for these languages.
CONFIGURE_ARGS+=	--disable-hspell
CONFIGURE_ARGS+=	--disable-uspell
CONFIGURE_ARGS+=	--disable-voikko

post-install:
	cd ${DESTDIR}${PREFIX}/share && ${MV} enchant/enchant.ordering examples/enchant-1.ordering

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
