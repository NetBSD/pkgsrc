# $NetBSD: Makefile,v 1.5 2003/07/21 17:16:34 martti Exp $
#

DISTNAME=		yup-r1-rel
PKGNAME=		yup-1.0
WRKSRC=			${WRKDIR}/yup-r1
CATEGORIES=		print
MASTER_SITES=		http://redback.spyda.net/~mjch/yup/
EXTRACT_SUFX=		.tgz

MAINTAINER=		grant@NetBSD.org
COMMENT=		Print multiple PostScript/ASCII pages per sheet

USE_PERL5=		# defined

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yup.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
