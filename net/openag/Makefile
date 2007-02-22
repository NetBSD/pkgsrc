# $NetBSD: Makefile,v 1.10 2007/02/22 19:01:23 wiz Exp $
#

DISTNAME=	OpenAG-1.1.1
PKGNAME=	openag-1.1.1
PKGREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/openags/
COMMENT=	Open Audio Galaxy client

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"

post-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/OpenAG
.for i in AUTHORS ChangeLog INSTALL NEWS README
		${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/share/doc/OpenAG/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
