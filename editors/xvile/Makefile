# $NetBSD: Makefile,v 1.20 2000/01/01 07:10:26 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:58:03 gj Exp
#

DISTNAME=	vile-9.0
PKGNAME=	xvile-9.0
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://id.wing.net/pub/pgf/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_XAW=	yes
MAKEFILE=	makefile
CONFIGURE_ARGS+= --with-screen=Xaw --with-xpm --with-perl --with-lib-dir=${X11BASE}/libexec
INSTALL_TARGET=	install install-perl

post-install:
	-@${MKDIR} -p ${PREFIX}/share/examples/xvile
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${BSD_INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/examples/xvile; \
	done

.include "../../mk/bsd.pkg.mk"
