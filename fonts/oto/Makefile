# $NetBSD: Makefile,v 1.3 2002/10/09 14:13:56 wiz Exp $
#

DISTNAME=	oto-0.4
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/oto/

MAINTAINER=	rxg@netbsd.org
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
