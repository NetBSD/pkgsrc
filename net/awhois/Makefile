# $NetBSD: Makefile,v 1.7 2010/02/26 10:28:33 wiz Exp $
#

DISTNAME=		awhois.sh-v1.61
PKGNAME=		awhois-1.61
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.planix.com/pub/Planix/
EXTRACT_SUFX=		# nowt

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.planix.com/pub/Planix/
COMMENT=		All-encompassing whois client wrapper

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR};

do-build:
	cd ${WRKSRC}; ${CP} ${DISTFILES} awhois; ${CHMOD} +x awhois;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/awhois ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
