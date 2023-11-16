# $NetBSD: Makefile,v 1.48 2023/11/16 12:01:08 wiz Exp $

DISTNAME=	ibus-array-0.2.2
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=lexical/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lexical/ibus-array/
COMMENT=	Array 30 Input Method for iBus
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config automake autoconf autopoint autoreconf msgfmt msgmerge

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	${RUN}cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} autoreconf -fiv

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
