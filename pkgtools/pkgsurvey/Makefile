# $NetBSD: Makefile,v 1.12 2012/09/11 23:19:39 asau Exp $
#

DISTNAME=	pkgsurvey-0.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@pkgsrc.org
COMMENT=	Utility to collate pkg information, and mail to central census site

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${SED} -e 's|\$${PKG_INFO}|${PKG_INFO}|'			\
		-e 's|\$${UNAME}|${UNAME}|g'				\
		${FILESDIR}/pkgsurvey.sh > ${DESTDIR}${PREFIX}/bin/pkgsurvey
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/pkgsurvey

.include "../../mk/bsd.pkg.mk"
