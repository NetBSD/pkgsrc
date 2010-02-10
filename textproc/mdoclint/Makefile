# $NetBSD: Makefile,v 1.10 2010/02/10 11:20:12 wiz Exp $

DISTNAME=	mdoclint-1.5
CATEGORIES=	textproc
MASTER_SITES=	# none
DISTFILES=	# none

OWNER=		wiz@NetBSD.org
#HOMEPAGE=	#
COMMENT=	Tool for verifying man pages

PKG_DESTDIR_SUPPORT=	user-destdir
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
