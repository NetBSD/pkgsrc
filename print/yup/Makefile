# $NetBSD: Makefile,v 1.7 2004/05/29 16:35:15 minskim Exp $
#

DISTNAME=		yup-r1-rel
PKGNAME=		yup-1.0
CATEGORIES=		print
MASTER_SITES=		http://redback.spyda.net/~mjch/yup/
EXTRACT_SUFX=		.tgz

MAINTAINER=		grant@NetBSD.org
COMMENT=		Print multiple PostScript/ASCII pages per sheet

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PERL5=		# defined

WRKSRC=			${WRKDIR}/yup-r1
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yup.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
