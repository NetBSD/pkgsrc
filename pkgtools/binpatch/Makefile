# $NetBSD: Makefile,v 1.1.1.1 2004/07/23 03:37:26 atatat Exp $
#

DISTNAME=	binpatch-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	atatat@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Trivial binary patch applicator

USE_BUILDLINK3=	yes

NO_CHECKSUM=	# defined

.include "../../mk/bsd.prefs.mk"

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-build:
	@(cd ${WRKSRC}; \
	  ${ECHO} "${CC} -o binpatch binpatch.c"; \
	  ${CC} -o binpatch binpatch.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binpatch ${PREFIX}/bin/binpatch
	${INSTALL_MAN} ${WRKSRC}/binpatch.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
