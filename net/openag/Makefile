# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:28 joerg Exp $
#

DISTNAME=	OpenAG-1.1.1
PKGNAME=	openag-1.1.1
PKGREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openags/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://homepage.mac.com/macdomeeu/dev/current/openag/
COMMENT=	Open Audio Galaxy client

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	yes

post-install:
		${INSTALL_MAN_DIR} ${PREFIX}/share/doc/OpenAG
.for i in AUTHORS ChangeLog INSTALL NEWS README
		${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/share/doc/OpenAG/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
