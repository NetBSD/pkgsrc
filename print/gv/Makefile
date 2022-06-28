# $NetBSD: Makefile,v 1.92 2022/06/28 11:35:28 wiz Exp $

DISTNAME=	gv-3.7.4
PKGREVISION=	12
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU:=gv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/gv/
COMMENT=	PostScript and PDF previewer
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gs:run makeinfo perl:run pkg-config

TEXINFO_REQD=		4.2
INFO_FILES=		yes
LIBS+=			${BUILDLINK_LDADD.getopt}

# this pkg does not work with std xaw, but xpm and xaw3d work
XAW_TYPE?=		3d
.include "../../mk/bsd.prefs.mk"
.if ${XAW_TYPE} == "standard"
XAW_TYPE=		3d
.endif

.if ${XAW_TYPE} == "neXtaw"
# The original configure links against Xaw3d, not Xaw.
BUILDLINK_TRANSFORM+=	l:Xaw3d:neXtaw
SUBST_CLASSES+=		gvnextaw
SUBST_MESSAGE.gvnextaw=	Patching gv to use neXtaw
SUBST_STAGE.gvnextaw=	pre-configure
SUBST_FILES.gvnextaw=	configure
SUBST_FILES.gvnextaw+=	src/paths.h
SUBST_SED.gvnextaw=	-e 's,<X11/Xaw3d/,<X11/neXtaw/,g'
.endif

# Solaris-2.{8,9}/sparc are missing setenv() and unsetenv()
# it is probably true that 5.6, 5.7, 5.8, and 5.9 all have
# this problem.  It appears that 5.10 does not need this flag.
.if ${OPSYS} == "SunOS" && !empty(OS_VERSION:M5.[6789])
CONFIGURE_ARGS+=	--enable-setenv-code
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "Darwin" \
	|| ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--enable-SIGCHLD-fallback
.endif

# XXX: bad configure test for libiconv from pkgsrc, so skip it.
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv_open=yes
LIBS+=			${BUILDLINK_LDADD.iconv}

SUBST_CLASSES+=		optlong1
SUBST_STAGE.optlong1=	post-extract
SUBST_FILES.optlong1=	src/gv_message.h
SUBST_SED.optlong1=	-e 's/\[-\]-/--/'

SUBST_CLASSES+=		optlong2
SUBST_STAGE.optlong2=	post-extract
SUBST_FILES.optlong2=	doc/gv.1
SUBST_SED.optlong2=	-e 's/\[\\-\]\\-/\\-\\-/'

REPLACE_PERL+=		src/gv-update-userconfig.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
