# $NetBSD: Makefile,v 1.55 2007/10/14 06:33:17 obache Exp $

DISTNAME=		vile-9.5
PKGNAME=		xvile-9.5r
CATEGORIES=		editors
MASTER_SITES=		ftp://invisible-island.net/vile/ \
			ftp://ftp.phred.org/pub/vile/
DIST_SUBDIR=		vile
EXTRACT_SUFX=		.tgz

PATCH_SITES=		${MASTER_SITES:=patches/}
PATCHFILES+=		vile-9.5a.patch.gz vile-9.5b.patch.gz vile-9.5c.patch.gz
PATCHFILES+=		vile-9.5d.patch.gz vile-9.5e.patch.gz vile-9.5f.patch.gz
PATCHFILES+=		vile-9.5g.patch.gz vile-9.5h.patch.gz vile-9.5i.patch.gz
PATCHFILES+=		vile-9.5j.patch.gz vile-9.5k.patch.gz vile-9.5l.patch.gz
PATCHFILES+=		vile-9.5m.patch.gz vile-9.5n.patch.gz vile-9.5o.patch.gz
PATCHFILES+=		vile-9.5p.patch.gz vile-9.5q.patch.gz vile-9.5r.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://invisible-island.net/vile/
COMMENT=		VI Like Emacs, X11 version -- a fully "X aware" vi work-alike

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
	${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget ${PREFIX}/bin/xvileget
	${INSTALL_DATA_DIR} ${EGDIR}
	set -e;							\
	for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EGDIR};		\
	done

.include "../../x11/libXpm/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
