# $NetBSD: Makefile,v 1.26 2000/09/06 08:16:15 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:58:03 gj Exp
#

DISTNAME=		vile-9.0
PKGNAME=		xvile-9.0
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.clark.net/pub/dickey/vile/ \
			ftp://ftp.uni-trier.de/pub/unix/editor/vile/ \
			ftp://ftp.phred.org/pub/vile/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org

USE_PERL5=		# defined
USE_X11BASE=		# defined
USE_XAW=		# defined
USE_XPM=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR}
CONFIGURE_ARGS+=	--with-screen=Xaw --with-xpm

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
CPPFLAGS+=		-DPERL_POLLUTE=1
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

MAKEFILE=		makefile
INSTALL_TARGET=		install install-perl

DATADIR=		${PREFIX}/share/xvile
FILTERDIR=		${PREFIX}/libexec/xvile
EGDIR=			${PREFIX}/share/examples/xvile

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget ${PREFIX}/bin/xvileget
	@${INSTALL_DATA_DIR} ${EGDIR}
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EGDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
