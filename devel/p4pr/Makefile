# $NetBSD: Makefile,v 1.7 2005/09/28 20:52:19 rillig Exp $
#

DISTNAME=	p4pr
PKGNAME=	${DISTNAME}-20010504
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/contrib/misc/
EXTRACT_SUFX=	.perl

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	Perforce file annotation with change, revision, and branch

DEPENDS+=	p4-[0-9]*:../../devel/p4

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# none
NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL=	${DISTFILES}

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTFILES} ${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
