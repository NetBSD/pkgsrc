# $NetBSD: Makefile,v 1.3 2003/07/17 21:32:03 grant Exp $
#

DISTNAME=	p4pr
PKGNAME=	${DISTNAME}-20010504
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/contrib/misc/
EXTRACT_SUFX=	.perl

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	Perforce file annotation with change, revision, and branch

DEPENDS+=	p4-[0-9]*:../../devel/p4

EXTRACT_ONLY=	# none
NO_BUILD=	# defined
USE_PERL5=	# defined
REPLACE_PERL=	${DISTFILES}

post-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTFILES} ${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
