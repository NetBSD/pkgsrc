# $NetBSD: Makefile,v 1.78 2022/07/04 20:10:53 wiz Exp $

DISTNAME=		vile-9.8v
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.invisible-island.net/pub/vile/current/ \
			https://invisible-mirror.net/archives/vile/current/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://invisible-island.net/vile/
COMMENT=		VI Like Emacs.  a vi "workalike", with many additional features
LICENSE=		gnu-gpl-v2

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR:Q}
USE_TOOLS+=		perl:run

REPLACE_PERL=		perl/vileget

CPPFLAGS.NetBSD+=	-DMISSING_EXTERN_ENVIRON

MAKE_FILE=		makefile
INSTALL_TARGET=		install install-doc install-perl

DATADIR=		${PREFIX}/share/vile
FILTERDIR=		${PREFIX}/libexec/vile
EGDIR=			${PREFIX}/share/examples/vile

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	set -e;								\
	for f in filters/spell.rc filters/filters.rc			\
		macros/digraphs.rc macros/pictmode.rc			\
		macros/manpage.rc visvile/visvile.rc; do		\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${EGDIR};	\
	done

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
