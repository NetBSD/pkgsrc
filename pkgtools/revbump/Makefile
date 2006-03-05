# $NetBSD: Makefile,v 1.5 2006/03/05 23:35:49 wiz Exp $
#

DISTNAME=		revbump-1.2
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		Tools for bumping PKGREVISIONs (for pkgsrc developers)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_TOOLS+=	perl:run
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	bin man/man1

do-build:
	${SED} -e "s!@PERL@!${PERL5}!g" ${FILESDIR}/blbump \
		> ${WRKDIR}/blbump
	${SED} -e "s!@PERL@!${PERL5}!g" ${FILESDIR}/finddepends \
		> ${WRKDIR}/finddepends
	${SED} -e "s!@PERL@!${PERL5}!g" ${FILESDIR}/revbump \
		> ${WRKDIR}/revbump

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/blbump ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/blbump.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKDIR}/finddepends ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/finddepends.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKDIR}/revbump ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/revbump.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
