# $NetBSD: Makefile,v 1.10 2020/03/20 11:57:56 nia Exp $

DISTNAME=		wsbasic-1_2_7
PKGNAME=		${DISTNAME:S/_/./g}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wsbasic/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wsbasic.sourceforge.net/
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
