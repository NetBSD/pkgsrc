# $NetBSD: Makefile,v 1.17 2022/11/27 22:18:48 nikita Exp $
#

DISTNAME=		mb2md-3.20.pl
PKGNAME=		${DISTNAME:S/.pl$//}
PKGREVISION=		11
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://batleth.sapienti-sat.org/projects/mb2md/
COMMENT=		Converts one or more mboxes to maildirs
LICENSE=		public-domain

DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate

WRKSRC=			${WRKDIR}

USE_TOOLS+=		perl:run
REPLACE_PERL=		${DISTNAME}

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
