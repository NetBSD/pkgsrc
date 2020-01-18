# $NetBSD: Makefile,v 1.7 2020/01/18 23:35:28 rillig Exp $
#

DISTNAME=	liblinebreak-2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vimgadgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vimgadgets.sourceforge.net/liblinebreak/
COMMENT=	Library for line breaking in a Unicode sequence

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	share/doc/liblinebreak

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/liblinebreak

.include "../../mk/bsd.pkg.mk"
