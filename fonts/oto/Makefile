# $NetBSD: Makefile,v 1.1.1.1 2002/07/21 19:20:24 wiz Exp $
#

DISTNAME=	oto-0.4
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/oto/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/oto/
COMMENT=	list and modify OpenType font files

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/oto
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/oto

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/libgetopt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
