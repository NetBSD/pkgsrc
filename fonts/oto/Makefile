# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:10 joerg Exp $
#

DISTNAME=	oto-0.4
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/oto/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/oto/
COMMENT=	List and modify OpenType font files

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/oto
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/oto

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
