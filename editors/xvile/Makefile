# $NetBSD: Makefile,v 1.62 2011/08/14 12:38:58 obache Exp $

DISTNAME=		vile-9.7
PKGNAME=		x${DISTNAME}
PKGREVISION=		4
CATEGORIES=		editors
MASTER_SITES=		ftp://invisible-island.net/vile/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://invisible-island.net/vile/
COMMENT=		VI Like Emacs, X11 version -- a fully "X aware" vi work-alike

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../../editors/vile/distinfo
PATCHDIR=		${.CURDIR}/../../editors/vile/patches

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-imake
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${DATADIR:Q}
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR:Q}

MAKE_FILE=		makefile
INSTALL_TARGET=		install install-doc install-perl

REPLACE_PERL=		perl/vileget
USE_TOOLS+=		perl:run

DATADIR=		${PREFIX}/share/xvile
FILTERDIR=		${PREFIX}/libexec/xvile
EGDIR=			${PREFIX}/share/examples/xvile

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-screen=Xaw3d
CONFIGURE_ARGS+=	--with-Xaw3d
.else
CONFIGURE_ARGS+=	--with-screen=Xaw
.endif
CONFIGURE_ARGS+=	--with-xpm

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget 			\
		${DESTDIR}${PREFIX}/bin/xvileget
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	set -e;								\
	for f in filters/spell.rc filters/filters.rc			\
		macros/digraphs.rc macros/pictmode.rc			\
		macros/manpage.rc visvile/visvile.rc; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${EGDIR};	\
	done

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
