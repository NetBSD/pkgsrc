# $NetBSD: Makefile,v 1.21 2001/01/07 01:48:19 wiz Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp

DISTNAME=		vile-9.0
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.clark.net/pub/dickey/vile/ \
			ftp://ftp.uni-trier.de/pub/unix/editor/vile/ \
			ftp://ftp.phred.org/pub/vile/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org

USE_PERL5=		# defined
USE_CURSES=		# defined

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

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget ${PREFIX}/bin/vileget
	@${INSTALL_DATA_DIR} ${EGDIR}
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EGDIR};		\
	done

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CPPFLAGS+=		-DHAVE_NCURSES_H
CONFIGURE_ARGS+=	--with-screen=ncurses
.endif

.include "../../mk/bsd.pkg.mk"
