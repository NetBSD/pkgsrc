# $NetBSD: Makefile,v 1.10 2012/10/03 21:54:33 wiz Exp $
#

DISTNAME=	p4pr
PKGNAME=	${DISTNAME}-20010504
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/contrib/misc/
EXTRACT_SUFX=	.perl

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	Perforce file annotation with change, revision, and branch

DEPENDS+=	p4-[0-9]*:../../devel/p4

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# none
NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL=	${DISTFILES}

INSTALLATION_DIRS=	bin

post-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTFILES} \
		${DESTDIR}${PREFIX}/bin/${DISTNAME}

.include "../../mk/bsd.pkg.mk"
