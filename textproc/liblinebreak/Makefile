# $NetBSD: Makefile,v 1.8 2020/03/20 11:58:27 nia Exp $
#

DISTNAME=	liblinebreak-2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vimgadgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vimgadgets.sourceforge.net/liblinebreak/
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
