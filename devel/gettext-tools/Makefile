# $NetBSD: Makefile,v 1.15 2011/04/12 17:41:29 adam Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}
COMMENT=	Tools for providing messages in different languages

#MAKE_JOBS_SAFE=		no

DISTINFO_FILE=	${.CURDIR}/../../devel/gettext/distinfo
PATCHDIR=	${.CURDIR}/../../devel/gettext/patches

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ= ac_cv_prog_JAR=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
CONFIGURE_ENV+=		ac_cv_libexpat=no
LDFLAGS.AIX+=		-Wl,-brtl

SHLIBTOOL_OVERRIDE=	# empty
INFO_FILES=		yes

BROKEN_GETTEXT_DETECTION=	yes
USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
