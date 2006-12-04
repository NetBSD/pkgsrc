# $NetBSD: Makefile,v 1.54.2.1 2006/12/04 08:46:25 ghen Exp $

DISTNAME=	tar-1.15.1
PKGNAME=	gtar-base-1.15.1
PKGREVISION=	4
SVR4_PKGNAME=	gtarb
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=tar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The GNU tape archiver with remote magnetic tape support

CONFLICTS=	gcpio-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX) && ${GNU_PROGRAM_PREFIX} != ""
GTAR_PROGRAM_PREFIX?=	${GNU_PROGRAM_PREFIX}
.else
GTAR_PROGRAM_PREFIX?=	g
.endif

.if ${GTAR_PROGRAM_PREFIX} == ""
# pax installs a "tar" also
CONFLICTS+=		pax-[0-9]*
.else
CONFIGURE_ARGS+=	--program-prefix=${GTAR_PROGRAM_PREFIX:Q}
.endif

# lie to configure about gettext -- it does not need GNU gettext
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl=yes

PLIST_SUBST+=		GTAR_PROGRAM_PREFIX=${GTAR_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX
BUILD_DEFS+=		GTAR_PROGRAM_PREFIX

TEST_TARGET=		check

.if ${GTAR_PROGRAM_PREFIX} != "g"
PLIST_SUBST+=		IF_BIN_GTAR=""
.else
PLIST_SUBST+=		IF_BIN_GTAR="@comment "
.endif

# don't include rmt if gtar won't build it
.if ${OPSYS} != "Interix"
PLIST_SUBST+=		IF_LIBEXEC_RMT=""
.else
PLIST_SUBST+=		IF_LIBEXEC_RMT="@comment "
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/gtar.1 \
		${PREFIX}/${PKGMANDIR}/man1/${GTAR_PROGRAM_PREFIX}tar.1
.if ${GTAR_PROGRAM_PREFIX} != "g"
	${LN} -sf ${GTAR_PROGRAM_PREFIX}tar ${PREFIX}/bin/"gtar"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
