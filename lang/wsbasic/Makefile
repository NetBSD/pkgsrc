# $NetBSD: Makefile,v 1.9 2020/01/18 23:32:46 rillig Exp $

DISTNAME=		wsbasic-1_2_7
PKGNAME=		${DISTNAME:S/_/./g}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wsbasic/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://wsbasic.sourceforge.net/
COMMENT=		Simple BASIC interpreter
LICENSE=		gnu-gpl-v2

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
