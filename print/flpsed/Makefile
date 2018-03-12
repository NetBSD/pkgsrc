# $NetBSD: Makefile,v 1.14 2018/03/12 11:17:26 wiz Exp $

DISTNAME=		flpsed-0.4.4
PKGREVISION=		2
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
