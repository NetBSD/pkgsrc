# $NetBSD: Makefile,v 1.9 2013/02/16 11:24:09 wiz Exp $

DISTNAME=		flpsed-0.3.9
PKGREVISION=		5
CATEGORIES=		print
MASTER_SITES=		http://www.ecademix.com/JohannesHofmann/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ecademix.com/JohannesHofmann/flpsed.html
COMMENT=		WYSIWYG PostScript2 annotator

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake gs:run

INSTALLATION_DIRS+=	share/doc/flpsed

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/flpsed

.include "../../x11/fltk13/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
