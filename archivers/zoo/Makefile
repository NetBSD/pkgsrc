# $NetBSD: Makefile,v 1.21 2004/12/03 15:14:51 wiz Exp $
# FreeBSD Id: Makefile,v 1.8 1997/08/10 22:31:36 fenner Exp
#

DISTNAME=       zoo-2.10pl1
PKGNAME=	zoo-2.10.1
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Manipulate archives of files in compressed form

LICENSE=	zoo-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

BUILD_TARGET=     bsdansi
MAKEFILE=       makefile

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/bsd.pkg.mk"
