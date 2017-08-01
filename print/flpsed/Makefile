# $NetBSD: Makefile,v 1.13 2017/08/01 17:40:15 wiz Exp $

DISTNAME=		flpsed-0.4.4
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		http://www.ecademix.com/JohannesHofmann/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.ecademix.com/JohannesHofmann/flpsed.html
COMMENT=		WYSIWYG PostScript2 annotator
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake gs:run

INSTALLATION_DIRS+=	share/doc/flpsed

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/flpsed

.include "../../x11/fltk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
