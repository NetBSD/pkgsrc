# $NetBSD: Makefile,v 1.5.2.1 2018/08/19 12:37:34 bsiegert Exp $

VERSION=	0.1
PKGNAME=	line-purple-${VERSION}
PKGREVISION=	4

CATEGORIES=	chat

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://altrepo.eu/git/purple-line/
COMMENT=	LINE protocol plugin for libpurple (pidgin, finch)

# XXX archive is at a github-type site, but its name doesn't
# match "https://github.com/account", couldn't figure out
# pkgsrc GITHUB* vars to work for fetching
#ALTREPO_TAG=	51cef1a66f6f4b1a90bd58a3746a2ea27fc74c36

BROKEN=		LINE bans third-party clients, use at your own risk

MASTER_SITES=   ${HOMEPAGE:=repository/}
EXTRACT_SUFX=	.zip
DISTNAME=	archive
DIST_SUBDIR=	${PKGNAME_NOREV}-20180221

LICENSE=	mit

WRKSRC=		${WRKDIR}/purple-line.git

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

USE_LANGUAGES=	c++

BUILDLINK_API_DEPENDS.libthrift+=   libthrift>=0.11.0

INSTALLATION_DIRS=	lib/purple-2 \
			share/pixmaps/pidgin/protocols/16 \
			share/pixmaps/pidgin/protocols/22 \
			share/pixmaps/pidgin/protocols/48 \
			share/pixmaps/pidgin/protocols/scalable \
			share/doc/line-purple

PIDGIN_PROTO_DIR=	${DESTDIR}${PREFIX}/share/pixmaps/pidgin/protocols

do-install:
		cd ${WRKSRC}/libpurple && ${LIBTOOL} --mode=install \
		  ${INSTALL_LIB} libline.la ${DESTDIR}${PREFIX}/lib/purple-2
		for i in 16 22 48; do cd ${WRKSRC}/icons && \
		  ${INSTALL_DATA} $$i/line.png ${PIDGIN_PROTO_DIR}/$$i; done
		${INSTALL_DATA} ${WRKSRC}/icons/scalable/line.svg \
		  ${DESTDIR}${PREFIX}/share/pixmaps/pidgin/protocols/scalable
		${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/line-purple

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libthrift/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
