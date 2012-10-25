# $NetBSD: Makefile,v 1.40 2012/10/25 06:55:50 asau Exp $

DISTNAME=	glimpse-4.18.5
PKGREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://webglimpse.net/trial/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webglimpse.net/
COMMENT=	Text search engine
LICENSE=	glimpse-license

RESTRICTED=	Redistribution only on non-profit basis.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# both install bin/agrep (approx. grep)
CONFLICTS+=	tre>=0.7.5nb6

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	yes
MAKE_FLAGS=	mandir=${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS=	share/doc/glimpse

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/glimpse

.include "../../mk/bsd.pkg.mk"
