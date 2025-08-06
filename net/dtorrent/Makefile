# $NetBSD: Makefile,v 1.10 2025/08/06 14:01:53 wiz Exp $
#

DISTNAME=	ctorrent-dnh3.3.2
PKGNAME=	dtorrent-3.3.2
PKGREVISION=	5
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && ${OS_VERSION:R} > 15
CFLAGS+=		-DHAVE_CLOCKID_T
.endif

DOCDIR=			share/doc/ctorrent

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/UserGuide ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
