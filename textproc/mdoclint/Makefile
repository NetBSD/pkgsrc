# $NetBSD: Makefile,v 1.32 2013/09/30 09:36:45 wiz Exp $

DISTNAME=	mdoclint-1.24
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none

OWNER=		wiz@NetBSD.org
#HOMEPAGE=	#
COMMENT=	Tool for verifying man pages
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CONFLICTS=	mdocml<1.6.9

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	do-configure
SUBST_FILES.perl=	mdoclint
SUBST_SED.perl+=	-e 's,@PERL5@,${PERL5},g'
SUBST_MESSAGE.perl=	Fixing path to perl.

do-extract:
	cd ${FILESDIR} && cp mdoclint* ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mdoclint ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/mdoclint.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
