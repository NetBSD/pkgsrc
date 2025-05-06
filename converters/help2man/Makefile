# $NetBSD: Makefile,v 1.74 2025/05/06 10:09:35 jperkin Exp $

DISTNAME=	help2man-1.49.3
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU:=help2man/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	arved@arved.at
HOMEPAGE=	https://www.gnu.org/software/help2man/
COMMENT=	Generate simple manual pages from program output
LICENSE=	gnu-gpl-v3

DEPENDS+=		p5-gettext>=1.01:../../devel/p5-gettext

USE_GCC_RUNTIME=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_ICONV=	no

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing install lib paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.in
SUBST_SED.paths=	-e 's,(libdir)/help2man,(libdir),g'

INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

.if ${OPSYS} == "Darwin"
SUBST_CLASSES+=		shlibarg
SUBST_STAGE.shlibarg=	pre-configure
SUBST_FILES.shlibarg=	Makefile.in
SUBST_SED.shlibarg=	-e 's, -shared , -dynamiclib -install_name ${PREFIX}/lib/bindtextdomain.${SHLIB_EXT} ,g'
.endif

SUBST_CLASSES+=		soext
SUBST_MESSAGE.soext=	Fixing shared library suffix
SUBST_NOOP_OK.soext=	yes
SUBST_STAGE.soext=	pre-configure
SUBST_FILES.soext=	bindtextdomain.c
SUBST_FILES.soext+=	Makefile.in
SUBST_SED.soext+=	-e 's,bindtextdomain\.so,bindtextdomain.${SHLIB_EXT},g'
SUBST_SED.soext+=	-e 's,$$(preload)\.so,$$(preload).${SHLIB_EXT},g'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
