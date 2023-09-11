# $NetBSD: Makefile,v 1.3 2023/09/11 13:50:33 ryoon Exp $

DISTNAME=		fsnotifier-0.0.20190228
PKGNAME=		intellij-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=idea4bsd/}
GITHUB_PROJECT=		fsnotifier
GITHUB_TAG=		bb7815166319ba46c27809ed8fc0c6b5fa14f869

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://github.com/idea4bsd/fsnotifier
COMMENT=		File system monitoring utility for IntelliJ IDEA IDE
LICENSE=		apache-2.0

INTELLIJCEDIR=		intellij-ce-bin
PYCHARMCEDIR=		pycharm-bin
INSTALLATION_DIRS=	${INTELLIJCEDIR}/bin ${PYCHARMCEDIR}/bin

PLIST_SUBST+=		INTELLIJCEDIR=${INTELLIJCEDIR}
PLIST_SUBST+=		PYCHARMCEDIR=${PYCHARMCEDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsnotifier \
		${DESTDIR}${PREFIX}/${INTELLIJCEDIR}/bin/fsnotifier
	${INSTALL_PROGRAM} ${WRKSRC}/fsnotifier \
		${DESTDIR}${PREFIX}/${PYCHARMCEDIR}/bin/fsnotifier

.include "../../devel/libinotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
