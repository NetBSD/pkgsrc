# $NetBSD: Makefile,v 1.17 2004/01/22 07:18:43 grant Exp $
# FreeBSD Id: Makefile,v 1.9 1997/08/10 22:31:19 fenner Exp
#

DISTNAME=       ha0999
PKGNAME=        ha-0.999b
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tgz

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	The HA archiver using the HSC compression method

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	yes

MAKEFILE=       makefile.nix
MAKE_FLAGS=     CC="${CC}"
ALL_TARGET=     ha
USE_GNU_TOOLS+=	make

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ha ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
