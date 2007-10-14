# $NetBSD: Makefile,v 1.49 2007/10/14 04:53:35 obache Exp $

DISTNAME=		vile-9.5
PKGNAME=		${DISTNAME}r
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
COMMENT=		VI Like Emacs.  a vi "workalike", with many additional features

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${DATADIR:Q}
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR:Q}
USE_TOOLS+=		perl:run

REPLACE_PERL=		perl/vileget

CPPFLAGS.NetBSD+=	-DMISSING_EXTERN_ENVIRON

MAKE_FILE=		makefile
INSTALL_TARGET=		install install-perl

DATADIR=		${PREFIX}/share/vile
FILTERDIR=		${PREFIX}/libexec/vile
EGDIR=			${PREFIX}/share/examples/vile

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget ${PREFIX}/bin/vileget
	${INSTALL_DATA_DIR} ${EGDIR}
	set -e;							\
	for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EGDIR};		\
	done

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
