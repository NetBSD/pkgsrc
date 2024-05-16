# $NetBSD: Makefile,v 1.76 2024/05/16 06:15:26 wiz Exp $

DISTNAME=		auctex-13.3
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=auctex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/auctex/
COMMENT=		Enhanced LaTeX mode for Emacs
LICENSE=		gnu-gpl-v3

TOOL_DEPENDS+=		tex-texlive-scripts-extra-[0-9]*:../../print/tex-texlive-scripts-extra
DEPENDS+=		texlive-collection-latex>=2014:../../meta-pkgs/texlive-collection-latex

EMACS_VERSIONS_ACCEPTED=	emacs29 emacs29nox emacs28 emacs28nox emacs27 emacs27nox emacs26 emacs26nox

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake makeinfo perl
GNU_CONFIGURE=		YES

CONFIGURE_ENV=		GS=${PREFIX}/bin/gs
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${EMACS_FLAVOR}}
CONFIGURE_ARGS+=	--enable-preview
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONFIGURE_ARGS.emacs=	--with-lispdir=${EMACS_LISPPREFIX}

# We are not building an XEmacs package!
CONFIGURE_ARGS.xemacs=	--without-packagedir
CONFIGURE_ARGS.xemacs+=	--with-lispdir=${EMACS_LISPPREFIX}

MAKEFLAGS+=		EMACS=${EMACS_BIN:Q}

BUILD_DEFS+=		VARBASE

EMACS_MODULES=		base

MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}
INFO_FILES=		YES

TEXMFDIR=		share/texmf-local

INSTALLATION_DIRS=	share/doc/auctex
INSTALLATION_DIRS+=	${EMACS_INFOPREFIX}
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX}/auctex
INSTALLATION_DIRS+=	${TEXMFDIR}/tex/latex/preview

MAKE_DIRS_PERMS+=	${VARBASE}/auctex ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777

.include "../../print/ghostscript/buildlink3.mk"
.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
