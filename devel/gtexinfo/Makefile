# $NetBSD: Makefile,v 1.78 2012/09/18 18:30:58 jperkin Exp $

DISTNAME=		texinfo-4.13
PKGNAME=		g${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=texinfo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		GNU info documentation utilities
LICENSE=		gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		bash
GNU_CONFIGURE=		yes
INFO_FILES=		yes
TEST_TARGET=		check
PLIST_SRC=		${PKGDIR}/PLIST

PKGSRC_INFOPATH=	${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}
MAKE_ENV+=		PKGSRC_INFOPATH=${PKGSRC_INFOPATH:Q}

REPLACE_BASH+=		util/texi2dvi

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This need to be defined here to override the setting in texinfo.mk
INSTALL_INFO=		${PREFIX}/bin/install-info
