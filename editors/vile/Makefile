# $NetBSD: Makefile,v 1.16 1999/12/26 17:57:50 tron Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp

DISTNAME=	vile-9.0
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://ftp.uni-trier.de/pub/unix/editor/vile/ \
		ftp://ftp.phred.org/pub/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

DEPENDS+=	ncurses-4.2:../../devel/ncurses

MAKEFILE=		makefile
GNU_CONFIGURE=		yes
CFLAGS+=		-DHAVE_NCURSES_H
CONFIGURE_ARGS+=	--with-perl \
			--with-libdir-path=${PREFIX}/libexec \
			--with-screen=ncurses
USE_PERL5=		yes

INSTALL_TARGET=	install install-perl

post-install:
	-@${MKDIR} -p ${PREFIX}/share/examples/vile
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${BSD_INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/examples/vile; \
	done

.include "../../mk/bsd.pkg.mk"
