# $NetBSD: Makefile,v 1.11 2001/09/09 20:36:12 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/08/10 22:31:36 fenner Exp 
#

DISTNAME=       zoo-2.10pl1
PKGNAME=	zoo-2.10.1
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/

MAINTAINER=	packages@netbsd.org
COMMENT=	Manipulate archives of files in compressed form

LICENSE=	zoo-license

USE_BUILDLINK_ONLY=	yes
WRKSRC=		${WRKDIR}
ALL_TARGET=     bsdansi
MAKEFILE=       makefile
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include "../../mk/bsd.pkg.mk"
