# $NetBSD: Makefile,v 1.25 2011/04/22 13:44:49 obache Exp $
#

DISTNAME=	grep-2.5.3
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-perl-regexp
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		makeinfo msgfmt
INFO_FILES=		# PLIST
TEXINFO_REQD=		4.0
CONFIGURE_ENV+=		MKDIR_P=${INSTALL_DATA_DIR:Q}

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
