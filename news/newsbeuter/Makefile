# $NetBSD: Makefile,v 1.22 2019/07/01 04:08:44 ryoon Exp $

DISTNAME=	newsbeuter-2.9
PKGREVISION=	20
CATEGORIES=	news
MASTER_SITES=	https://www.newsbeuter.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.newsbeuter.org/
COMMENT=	Open-source RSS/Atom feed reader for text terminals
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt perl
USE_GNU_ICONV=	yes
USE_NCURSES=	yes

REPLACE_PERL+=	txt2h.pl

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX} mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing distribution Makefile...
SUBST_FILES.makefile=	${MAKE_FILE}
SUBST_SED.makefile=	-e 's/^ifneq.*//; s/^endif.*//'
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/stfl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
