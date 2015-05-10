# $NetBSD: Makefile,v 1.14 2015/05/10 19:47:03 joerg Exp $
#

PKGNAME=	pkgsurvey-1.0
CATEGORIES=	pkgtools

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
