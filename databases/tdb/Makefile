# $NetBSD: Makefile,v 1.34 2019/01/03 19:35:24 adam Exp $

DISTNAME=	tdb-1.3.16
CATEGORIES=	databases
MASTER_SITES=	http://www.samba.org/ftp/tdb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tdb.samba.org/
COMMENT=	Small database system which uses files to store data
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

# both install tdbtool and tdbdump
CONFLICTS+=	samba<3.6.6nb3

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	${WRKSRC}/buildtools/bin/waf
CONFIGURE_ARGS+=	configure
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--abi-check-disable
CONFIGURE_ARGS+=	--disable-symbol-versions
.if defined(MAKE_JOBS) && !empty(MAKE_JOBS) && !(defined(MAKE_JOBS_SAFE) && !empty(MAKE_JOBS_SAFE:M[nN][oO]))
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS}
.else
CONFIGURE_ARGS+=	--jobs=1
.endif
TEST_TARGET=		test

PKGCONFIG_OVERRIDE=	tdb.pc.in

USE_GCC_RUNTIME=	yes

PYTHON_VERSIONS_ACCEPTED=	27

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	buildtools/bin/waf

SUBST_CLASSES+=		docbook
SUBST_MESSAGE.docbook=	Fixing docbook URLs.
SUBST_FILES.docbook+=	buildtools/wafsamba/samba_conftests.py
SUBST_FILES.docbook+=	buildtools/wafsamba/wafsamba.py
SUBST_STAGE.docbook=	pre-configure
SUBST_SED.docbook+=	-e 's,http://docbook.sourceforge.net/release/xsl/current,${PREFIX}/share/xsl/docbook,g'

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
