# $NetBSD: Makefile,v 1.18 2025/11/17 11:01:32 wiz Exp $

DISTNAME=	${PKGNAME}b-src
PKGNAME=	makeztxt-1.40
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gutenpalm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gutenpalm.sourceforge.net/makeztxt.php
COMMENT=	ASCII text to Palm zTXT database converter

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}b

INSTALLATION_DIRS=	bin share/doc/makeztxt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makeztxt ${DESTDIR}${PREFIX}/bin
.for doc in COPYING ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/makeztxt
.endfor

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
