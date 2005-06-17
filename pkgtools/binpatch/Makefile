# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:29 jlam Exp $
#

DISTNAME=	binpatch-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	atatat@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Trivial binary patch applicator


NO_CHECKSUM=	# defined

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin man/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	@(cd ${WRKSRC}; \
	  ${ECHO} "${CC} -o binpatch binpatch.c"; \
	  ${CC} -o binpatch binpatch.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binpatch ${PREFIX}/bin/binpatch
	${INSTALL_MAN} ${WRKSRC}/binpatch.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
