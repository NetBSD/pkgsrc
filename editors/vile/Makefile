# $NetBSD: Makefile,v 1.24 2001/12/07 00:36:26 wiz Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp

DISTNAME=		vile-9.0
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.clark.net/pub/dickey/vile/ \
			ftp://ftp.uni-trier.de/pub/unix/editor/vile/ \
			ftp://ftp.phred.org/pub/vile/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
COMMENT=		VI Like Emacs.  a vi "workalike", with many additional features

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR}

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
CPPFLAGS+=		-DPERL_POLLUTE=1

MAKEFILE=		makefile
INSTALL_TARGET=		install install-perl

DATADIR=		${PREFIX}/share/vile
FILTERDIR=		${PREFIX}/libexec/vile
EGDIR=			${PREFIX}/share/examples/vile

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget ${PREFIX}/bin/vileget
	@${INSTALL_DATA_DIR} ${EGDIR}
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EGDIR};		\
	done

.include "../../devel/ncurses/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
