# $NetBSD: Makefile,v 1.5 2003/07/17 21:37:24 grant Exp $
#

DISTNAME=	oto-0.4
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/oto/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/oto/
COMMENT=	list and modify OpenType font files

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/oto
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/oto

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/libgetopt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
