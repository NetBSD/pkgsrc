# $NetBSD: Makefile,v 1.25 2000/08/23 23:14:23 tron Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/06 19:58:03 gj Exp
#

DISTNAME=	vile-9.0
PKGNAME=	xvile-9.0
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.clark.net/pub/dickey/vile/ \
		ftp://ftp.uni-trier.de/pub/unix/editor/vile/ \
		ftp://ftp.phred.org/pub/vile/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
USE_PERL5=	YES
USE_XAW=	YES
USE_XPM=	YES
MAKEFILE=	makefile
CONFIGURE_ARGS+= --with-screen=Xaw --with-xpm --with-perl --with-lib-dir=${X11PREFIX}/libexec
INSTALL_TARGET=	install install-perl

post-install:
	-@${MKDIR} ${PREFIX}/share/examples/xvile
	@for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${BSD_INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/examples/xvile; \
	done

.include "../../mk/bsd.pkg.mk"
