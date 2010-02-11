# $NetBSD: Makefile,v 1.11 2010/02/11 22:28:40 joerg Exp $
#

DISTNAME=	OpenAG-1.1.1
PKGNAME=	openag-1.1.1
PKGREVISION=	2
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/openags/
COMMENT=	Open Audio Galaxy client

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"

INSTALLATION_DIRS+=	share/doc/OpenAG

post-install:
.for i in AUTHORS ChangeLog INSTALL NEWS README
		${INSTALL_MAN} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/OpenAG/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
