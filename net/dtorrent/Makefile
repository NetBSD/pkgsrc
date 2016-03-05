# $NetBSD: Makefile,v 1.7 2016/03/05 11:29:03 jperkin Exp $
#

DISTNAME=	ctorrent-dnh3.3.2
PKGNAME=	dtorrent-3.3.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dtorrent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rahul.net/dholmes/ctorrent/
COMMENT=	Enhanced CTorrent, a BitTorrent console client written in C/C++
LICENSE=	gnu-gpl-v2

CONFLICTS=		ctorrent-[0-9]*
SUPERSEDES=		ctorrent-[0-9]*

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

DOCDIR=			share/doc/ctorrent

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/UserGuide ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
