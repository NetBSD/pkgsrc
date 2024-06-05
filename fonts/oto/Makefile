# $NetBSD: Makefile,v 1.17 2024/06/05 16:59:17 ktnb Exp $
#

DISTNAME=	oto-0.5
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oto/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/oto/
COMMENT=	List and modify OpenType font files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	share/doc/oto

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/oto

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
