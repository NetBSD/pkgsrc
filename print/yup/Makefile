# $NetBSD: Makefile,v 1.2 2002/06/19 12:18:37 grant Exp $
#

DISTNAME=		yup-r1-rel
PKGNAME=		yup-1.0
CATEGORIES=		print
MASTER_SITES=		http://redback.spyda.net/~mjch/yup/
EXTRACT_SUFX=		.tgz

MAINTAINER=		grant@netbsd.org
COMMENT=		print multiple PostScript/ASCII pages per sheet

USE_PERL5=		# defined
WRKSRC=			${WRKDIR}/yup-r1

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yup.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
