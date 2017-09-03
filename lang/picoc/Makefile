# $NetBSD: Makefile,v 1.6 2017/09/03 09:22:57 wiz Exp $

DISTNAME=		picoc-2.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://picoc.googlecode.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://github.com/zsaleeba/picoc
COMMENT=		C interpreter
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/picoc

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picoc ${DESTDIR}${PREFIX}/bin/picoc

.include "../../devel/editline/buildlink3.mk"

.include "../../mk/readline.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
