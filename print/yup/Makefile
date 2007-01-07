# $NetBSD: Makefile,v 1.10 2007/01/07 09:14:09 rillig Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yup.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
