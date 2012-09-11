# $NetBSD: Makefile,v 1.76 2012/09/11 19:46:55 asau Exp $

DISTNAME=	tar-1.26
PKGNAME=	${DISTNAME:S/tar/gtar-base/}
PKGREVISION=	2
SVR4_PKGNAME=	gtarb
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=tar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The GNU tape archiver with remote magnetic tape support
LICENSE=	gnu-gpl-v3

CONFLICTS=	gcpio-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_FEATURES=		snprintf
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1 gnu/bin gnu/libexec gnu/man/man1

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--program-prefix=g

# lie to configure about gettext -- it does not need GNU gettext
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl=yes
# allow configure to run as root
CONFIGURE_ENV+=		FORCE_UNSAFE_CONFIGURE=1

PLIST_VARS+=		gtar rmt

TEST_TARGET=		check

# don't include rmt if gtar won't build it
.if ${OPSYS} != "Interix" && ${OPSYS} != "Darwin"
PLIST.rmt=		yes
.endif

# XXX see similar hack in coreutils.
.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		gt_cv_func_gnugettext3_libintl=yes
.endif

SYMLINKS		= bin/gtar gnu/bin/tar \
			man/man1/gtar.1 gnu/man/man1/tar.1 \
			libexec/grmt gnu/libexec/rmt

post-install:
	${INSTALL_MAN} ${FILESDIR}/gtar.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gtar.1
.for o n in ${SYMLINKS}
	${LN} -sf ${PREFIX}/${o} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
