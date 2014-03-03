# $NetBSD: Makefile,v 1.14 2014/03/03 03:34:32 obache Exp $
#

PKGNAME=	binpatch-1.0
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Trivial binary patch applicator
LICENSE=	beer-ware

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
