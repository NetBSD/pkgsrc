# $NetBSD: Makefile,v 1.20 2000/09/06 08:16:14 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp

DISTNAME=		vile-9.0
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.clark.net/pub/dickey/vile/ \
			ftp://ftp.uni-trier.de/pub/unix/editor/vile/ \
			ftp://ftp.phred.org/pub/vile/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org

USE_PERL5=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR}

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
CPPFLAGS+=		-DPERL_POLLUTE=1
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

MAKEFILE=		makefile
INSTALL_TARGET=		install install-perl

DATADIR=		${PREFIX}/share/vile
FILTERDIR=		${PREFIX}/libexec/vile
EGDIR=			${PREFIX}/share/examples/vile

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=		ncurses>=4.2:../../devel/ncurses
CPPFLAGS+=		-DHAVE_NCURSES_H
CONFIGURE_ARGS+=	--with-screen=ncurses
.endif

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget ${PREFIX}/bin/vileget
	@${INSTALL_DATA_DIR} ${EGDIR}
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EGDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
