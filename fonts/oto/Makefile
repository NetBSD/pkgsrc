# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:47 tv Exp $
#

DISTNAME=	oto-0.4
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/oto/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/oto/
COMMENT=	List and modify OpenType font files

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/oto
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/oto

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
