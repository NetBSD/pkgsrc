# $NetBSD: Makefile,v 1.2 2007/03/24 01:57:44 joerg Exp $

DISTNAME=		flpsed-0.3.9
CATEGORIES=		print
MASTER_SITES=		http://www.ecademix.com/JohannesHofmann/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ecademix.com/JohannesHofmann/flpsed.html
COMMENT=		WYSIWYG PostScript2 annotator

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake gs:run

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/flpsed
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/flpsed

.include "../../x11/fltk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
