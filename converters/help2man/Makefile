# $NetBSD: Makefile,v 1.50 2019/08/11 13:18:10 wiz Exp $

DISTNAME=	help2man-1.47.10
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU:=help2man/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	arved@arved.at
HOMEPAGE=	http://www.gnu.org/software/help2man/
COMMENT=	Generate simple manual pages from program output
LICENSE=	gnu-gpl-v3

DEPENDS+=		p5-gettext>=1.01:../../devel/p5-gettext

USE_GCC_RUNTIME=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run msgfmt gmake
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing install lib paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.in
SUBST_SED.paths=	-e 's,(libdir)/help2man,(libdir),g'

INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SOEXT=			dylib
SUBST_CLASSES+=		shlibarg
SUBST_STAGE.shlibarg=	pre-configure
SUBST_FILES.shlibarg=	Makefile.in
SUBST_SED.shlibarg=	-e 's, -shared , -dynamiclib -install_name ${PREFIX}/lib/bindtextdomain.${SOEXT} ,g'
.elif ${OBJECT_FMT} == "SOM"
SOEXT=			sl
.else
SOEXT=			so
.endif

SUBST_CLASSES+=		soext
SUBST_MESSAGE.soext=	Fixing shared library suffix
SUBST_STAGE.soext=	pre-configure
SUBST_FILES.soext=	bindtextdomain.c
SUBST_FILES.soext+=	Makefile.in
SUBST_SED.soext+=	-e 's,bindtextdomain\.so,bindtextdomain.${SOEXT},g'
SUBST_SED.soext+=	-e 's,$$(preload)\.so,$$(preload).${SOEXT},g'

PLIST_SUBST+=		SOEXT=${SOEXT}

post-patch:
	${TOUCH} -r ${WRKSRC}/help2man.PL.orig ${WRKSRC}/help2man.PL

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
