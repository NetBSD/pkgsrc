# $NetBSD: Makefile,v 1.9 2005/09/28 20:52:26 rillig Exp $
#

DISTNAME=		yup-r1-rel
PKGNAME=		yup-1.0
CATEGORIES=		print
MASTER_SITES=		http://redback.spyda.net/~mjch/yup/
EXTRACT_SUFX=		.tgz

MAINTAINER=		grant@NetBSD.org
COMMENT=		Print multiple PostScript/ASCII pages per sheet

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		perl:run

WRKSRC=			${WRKDIR}/yup-r1
NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yup.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
