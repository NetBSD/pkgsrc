# $NetBSD: Makefile,v 1.12 2005/02/17 05:58:28 uebayasi Exp $
#

DISTNAME=	ctags-5.5.4
PKGNAME=	ex${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctags/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://ctags.sourceforge.net/
COMMENT=	Exuberant (feature-filled) tagfile generator for vi, emacs and clones

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-macro-patterns
CONFIGURE_ARGS+=	--with-readlib
CONFIGURE_ARGS+=	--enable-custom-config=${PKG_SYSCONFDIR}/ctags.conf

CPPFLAGS+=		-DETAGS="\"exetags\""

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_FILES.man=	ctags.1
SUBST_SED.man=	\
	-e 's|^ctags \\-|exctags \\-|' \
	-e 's|fBctags|fBexctags|g' \
	-e 's|fBetags|fBexetags|g' \
	-e 's|"ctags|"exctags|g' \
	-e 's|"etags|"exetags|g' \
	-e 's|/usr/local|${LOCALBASE}|g'

SUBST_CLASSES+=		rename
SUBST_STAGE.rename=	post-patch
SUBST_FILES.rename=	c.c eiffel.c general.h lregex.c lua.c main.c \
			options.c parse.c routines.c
SUBST_SED.rename=	-e 's|__unused__|__unused_|g'

.include "../../mk/bsd.pkg.mk"
