# $NetBSD: Makefile,v 1.86 2019/11/03 10:39:11 rillig Exp $

.include "../../devel/gettext/Makefile.common"

COMMENT=	Tools for providing messages in different languages

DEPENDS+=	gettext-m4-${PKGVERSION_NOREV}{,nb[0-9]*}:../../devel/gettext-m4
DEPENDS+=	gettext-tools-${PKGVERSION_NOREV}{,nb[0-9]*}:../../devel/gettext-tools
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.18

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
SHLIBTOOL_OVERRIDE=	# empty
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--without-git
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
CONFIGURE_ENV+=		ac_cv_libexpat=no

INSTALLATION_DIRS+=	lib
TEST_TARGET=		check

BROKEN_GETTEXT_DETECTION=	yes
USE_BUILTIN.gettext=		no # force use of pkgsrc gettext-lib

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	glibc
.if ${OPSYS} == "Linux"
PLIST.glibc=	yes
.endif

do-install:
	cd ${WRKSRC}/gettext-tools && ${MAKE} install-gettextsrcSCRIPTS DESTDIR=${DESTDIR}
	cd ${WRKSRC}/gettext-tools/projects && ${MAKE} install DESTDIR=${DESTDIR}
	cd ${WRKSRC}/gettext-runtime && ${MAKE} install-gettextsrcDATA DESTDIR=${DESTDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-asprintf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
