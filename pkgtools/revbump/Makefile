# $NetBSD: Makefile,v 1.1.1.1 2005/01/05 00:31:38 wiz Exp $
#

DISTNAME=		revbump-1.0
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		Tools for bumping PKGREVISIONs (for pkgsrc developers)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_BUILDLINK=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_PERL5=	run
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	bin man/man8

do-build:
	${SED} -e "s!@PERL@!${PERL5}!g" ${FILESDIR}/revbump \
		> ${WRKDIR}/revbump
	${SED} -e "s!@PERL@!${PERL5}!g" ${FILESDIR}/blbump \
		> ${WRKDIR}/blbump

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/blbump ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/revbump ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
