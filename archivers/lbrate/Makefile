# $NetBSD: Makefile,v 1.3 2003/07/17 21:21:22 grant Exp $
# FreeBSD Id: ports/archivers/lbrate/Makefile,v 1.4 2002/06/19 08:18:05 sobomax Exp

DISTNAME=	lbrate-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/utils/compress/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/lbrate.html
COMMENT=	Extract/decompress CP/M LBR archives

USE_BUILDLINK2=	YES
MAKE_FLAGS+=	PREFIX=${PREFIX}
LBRATE_DOCSDIR=	${PREFIX}/share/doc/lbrate

post-install:
	@${INSTALL_DATA_DIR} ${LBRATE_DOCSDIR}
	for f in COPYING ChangeLog README TODO; do		\
	${INSTALL_DATA} ${WRKSRC}/$$f ${LBRATE_DOCSDIR}; done

.include "../../mk/bsd.pkg.mk"
