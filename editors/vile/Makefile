# $NetBSD: Makefile,v 1.15 1999/10/22 13:37:48 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:55:09 gj Exp
#

DISTNAME=	vile-8.3
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-perl  --with-libdir-path=${PREFIX}/libexec
USE_PERL5=	yes
INSTALL_TARGET=	install install-perl

post-install:
	-@${MKDIR} -p ${PREFIX}/share/examples/vile
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${BSD_INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/examples/vile; \
	done

.include "../../mk/bsd.pkg.mk"
