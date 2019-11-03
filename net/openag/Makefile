# $NetBSD: Makefile,v 1.15 2019/11/03 11:45:46 rillig Exp $
#

DISTNAME=	OpenAG-1.1.1
PKGNAME=	openag-1.1.1
PKGREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/openags/
COMMENT=	Open Audio Galaxy client


GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	wget:run

CONFIGURE_ENV+=	WGET=wget

.include "../../devel/zlib/buildlink3.mk"

INSTALLATION_DIRS+=	share/doc/OpenAG

post-install:
.for i in AUTHORS ChangeLog INSTALL NEWS README
	${INSTALL_MAN} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/OpenAG/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
