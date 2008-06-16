# $NetBSD: Makefile,v 1.9 2008/06/16 15:29:00 joerg Exp $
#

DISTNAME=	binpatch-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	atatat@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Trivial binary patch applicator

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CHECKSUM=	yes

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
