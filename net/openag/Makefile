# $NetBSD: Makefile,v 1.8 2006/06/06 18:02:48 joerg Exp $
#

DISTNAME=	OpenAG-1.1.1
PKGNAME=	openag-1.1.1
PKGREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://homepage.mac.com/macdomeeu/dev/current/openag/
COMMENT=	Open Audio Galaxy client

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

post-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/OpenAG
.for i in AUTHORS ChangeLog INSTALL NEWS README
		${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/share/doc/OpenAG/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
