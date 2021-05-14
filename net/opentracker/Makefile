# $NetBSD: Makefile,v 1.4 2021/05/14 12:28:10 nia Exp $

DISTNAME=	opentracker-0.0.20180526
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# https://erdgeist.org/gitweb/opentracker/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://erdgeist.org/arts/software/opentracker/
COMMENT=	Bittorrent tracker
LICENSE=	beer-ware

MAKE_FLAGS+=	LIBOWFAT_HEADERS=${PREFIX}/include/libowfat
MAKE_FLAGS+=	LIBOWFAT_LIBRARY=${PREFIX}/lib
MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin

.include "options.mk"

INSTALLATION_DIRS+=	bin ${EGDIR}

WRKSRC=		${WRKDIR}/opentracker

EGDIR=		share/examples/opentracker
CONF_FILES=	${EGDIR}/opentracker.conf.sample ${PKG_SYSCONFDIR}/opentracker.conf
RCD_SCRIPTS=	opentracker

post-install:
	${INSTALL_DATA} ${WRKSRC}/opentracker.conf.sample ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../devel/libowfat/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
