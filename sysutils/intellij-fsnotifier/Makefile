# $NetBSD: Makefile,v 1.4 2024/12/12 15:21:57 ryoon Exp $

DISTNAME=		fsnotifier
PKGNAME=		intellij-${DISTNAME}-20230725
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITLAB:=worthwhileit/bsd/}
GITLAB_PROJECT=		fsnotifier
GITLAB_TAG=		b96f269f637058461df482f4cf55037a5968d7a8

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://gitlab.com/worthwhileit/bsd/fsnotifier
COMMENT=		File system monitoring utility for IntelliJ IDEA IDE
LICENSE=		apache-2.0

WRKSRC=			${WRKDIR}/${DISTNAME}-${GITLAB_TAG}

USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DVERSION=1

INTELLIJCEDIR=		intellij-ce-bin
PYCHARMCEDIR=		pycharm-bin
INSTALLATION_DIRS=	${INTELLIJCEDIR}/bin ${PYCHARMCEDIR}/bin

PLIST_SUBST+=		INTELLIJCEDIR=${INTELLIJCEDIR}
PLIST_SUBST+=		PYCHARMCEDIR=${PYCHARMCEDIR}

.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
