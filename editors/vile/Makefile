# $NetBSD: Makefile,v 1.17 2000/01/01 05:03:59 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp

DISTNAME=	vile-9.0
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://ftp.uni-trier.de/pub/unix/editor/vile/ \
		ftp://ftp.phred.org/pub/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

MAKEFILE=		makefile
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-perl \
			--with-libdir-path=${PREFIX}/libexec
USE_PERL5=		yes

INSTALL_TARGET=	install install-perl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=		ncurses-4.2:../../devel/ncurses
CFLAGS+=		-DHAVE_NCURSES_H
CONFIGURE_ARGS+=	--with-screen=ncurses
.endif

post-install:
	-@${MKDIR} -p ${PREFIX}/share/examples/vile
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${BSD_INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/examples/vile; \
	done

.include "../../mk/bsd.pkg.mk"
