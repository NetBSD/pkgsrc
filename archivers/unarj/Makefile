# $NetBSD: Makefile,v 1.7 1999/05/22 22:07:03 tv Exp $

DISTNAME=       unarj-2.43
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unarj ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
