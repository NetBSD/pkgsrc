# $NetBSD: Makefile,v 1.12 2012/09/11 23:19:33 asau Exp $
#

DISTNAME=	binpatch-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Trivial binary patch applicator

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	@(cd ${WRKSRC}; \
	  ${ECHO} "${CC} -o binpatch binpatch.c"; \
	  ${CC} -o binpatch binpatch.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binpatch ${DESTDIR}${PREFIX}/bin/binpatch
	${INSTALL_MAN} ${WRKSRC}/binpatch.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
