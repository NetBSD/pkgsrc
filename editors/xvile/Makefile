# $NetBSD: Makefile,v 1.52 2006/09/09 02:41:59 obache Exp $

DISTNAME=		vile-9.5
PKGNAME=		xvile-9.5
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		ftp://dickey.his.com/vile/ \
			ftp://invisible-island.net/vile/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dickey.his.com/vile/vile.html
COMMENT=		VI Like Emacs, X11 version -- a fully "X aware" vi work-alike


GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${DATADIR:Q}
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR:Q}

MAKE_FILE=		makefile
INSTALL_TARGET=		install install-perl

DATADIR=		${PREFIX}/share/xvile
FILTERDIR=		${PREFIX}/libexec/xvile
EGDIR=			${PREFIX}/share/examples/xvile

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-screen=Xaw3d
CONFIGURE_ARGS+=	--with-Xaw3d
.else
XAW_TYPE=		standard
CONFIGURE_ARGS+=	--with-screen=Xaw
.endif
CONFIGURE_ARGS+=	--with-xpm

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget ${PREFIX}/bin/xvileget
	${INSTALL_DATA_DIR} ${EGDIR}
	for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EGDIR};		\
	done

.include "../../graphics/xpm/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
