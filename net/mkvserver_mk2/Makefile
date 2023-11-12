# $NetBSD: Makefile,v 1.6 2023/11/12 13:23:11 wiz Exp $

DISTNAME=	mkvserver_mk2-0.0.0.20200117
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=klaxa/}
GITHUB_PROJECT=	mkvserver_mk2
GITHUB_TAG=	c62abc30f4cca6147ddc732570b30fcb4bee30ec

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/klaxa/mkvserver_mk2
COMMENT=	Streaming solution to end all streaming problems
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server \
		${DESTDIR}${PREFIX}/bin/mkvserver_mk2

.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
