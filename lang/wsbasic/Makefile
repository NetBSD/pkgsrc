# $NetBSD: Makefile,v 1.5 2008/01/04 12:17:16 ghen Exp $

DISTNAME=		wsbasic-1_2_5
PKGNAME=		${DISTNAME:S/_/./g}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wsbasic/}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://wsbasic.sourceforge.net/
COMMENT=		Simple BASIC interpreter

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++

REPLACE_INTERPRETER+=	wsbasic
REPLACE.wsbasic.old=	\.\./wsbasic
REPLACE.wsbasic.new=	${PREFIX}/bin/wsbasic
REPLACE_FILES.wsbasic=	${WRKSRC}/scripts/*

INSTALLATION_DIRS=	bin share/wsbasic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wsbasic ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.b ${DESTDIR}${PREFIX}/share/wsbasic/
	${INSTALL_DATA} ${WRKSRC}/scripts/*.txt ${DESTDIR}${PREFIX}/share/wsbasic/

.include "../../mk/bsd.pkg.mk"
