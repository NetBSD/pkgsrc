# $NetBSD: Makefile,v 1.23 2024/05/06 08:27:49 jperkin Exp $

DISTNAME=	centerim5-5.0.1
PKGREVISION=	17
CATEGORIES=	chat
MASTER_SITES=	http://www.centerim.org/download/cim5/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://centerim.org/
COMMENT=	Text-mode multi-protocol instant messaging client using libpurple
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	aclocal autoconf autoheader automake autopoint
USE_TOOLS+=	pkg-config gettext msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++

HAS_CONFIGURE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

USE_LIBTOOL=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		equals
SUBST_STAGE.equals=	pre-configure
SUBST_MESSAGE.equals=	Use portable = instead of ==.
SUBST_FILES.equals+=	configure.ac
SUBST_SED.equals=	-e 's,== True,= True,g'

post-extract:
	rm ${WRKSRC}/version

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../lang/python/application.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
