# $NetBSD: Makefile,v 1.3 2013/07/15 02:02:24 ryoon Exp $

DISTNAME=		picoc-2.1
CATEGORIES=		lang
MASTER_SITES=		http://picoc.googlecode.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://code.google.com/p/picoc/
COMMENT=		C interpreter
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/picoc

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picoc ${DESTDIR}${PREFIX}/bin/picoc

.include "../../mk/readline.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
