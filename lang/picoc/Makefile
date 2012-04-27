# $NetBSD: Makefile,v 1.1.1.1 2012/04/27 04:48:44 agc Exp $

DISTNAME=		picoc-2.1
CATEGORIES=		lang
MASTER_SITES=		http://picoc.googlecode.com/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://code.google.com/p/picoc/
COMMENT=		C interpreter
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/picoc

PKG_DESTDIR_SUPPORT=	user-destdir
AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picoc ${DESTDIR}${PREFIX}/bin/picoc

.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
