# $NetBSD: Makefile,v 1.40 2018/11/16 13:02:46 bsiegert Exp $
#

DISTNAME=		enchant-1.6.0
PKGREVISION=		8
CATEGORIES=		textproc
MASTER_SITES=		http://www.abisource.com/downloads/enchant/1.6.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.abisource.com/projects/enchant/
COMMENT=		Generic spell checking library
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config autoconf
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes
CFLAGS.SunOS+=		-D__EXTENSIONS__

INSTALLATION_DIRS+=	share/examples
MAKE_DIRS+=		${PREFIX}/share/enchant
CONF_FILES=		${PREFIX}/share/examples/enchant-1.ordering ${PREFIX}/share/enchant/enchant.ordering

post-install:
	cd ${DESTDIR}${PREFIX}/share && ${MV} enchant/enchant.ordering examples/enchant-1.ordering

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
