# $NetBSD: Makefile,v 1.12 2015/01/20 11:24:33 obache Exp $

DISTNAME=	ibus-array-0.1.0
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus-array.googlecode.com/svn/tarballs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus-array/
COMMENT=	Array 30 Input Method for iBus
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	gmake pkg-config automake autoconf autopoint msgfmt msgmerge

WRKSRC=		${WRKDIR}

pre-configure:
	${RUN}cd ${WRKSRC};${PKGSRC_SETENV} ${CONFIGURE_ENV} ./autogen.sh

SUBST_CLASSES+=		epython
SUBST_STAGE.epython=	pre-configure
SUBST_FILES.epython=	setup/ibus-setup-array.in
SUBST_SED.epython=	-e 's;exec python;exec ${PYTHONBIN};g'

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
