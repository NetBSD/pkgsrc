# $NetBSD: Makefile,v 1.6 2012/10/23 17:18:38 asau Exp $

DISTNAME=	mping-2.01
CATEGORIES=	net
MASTER_SITES=	http://mping.uninett.no/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mping.uninett.no/
COMMENT=	Mping network statistics collector

GNU_CONFIGURE=		yes
USE_FEATURES+=		inet6

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mping ${DESTDIR}${PREFIX}/sbin/mping
	${INSTALL_MAN} ${WRKSRC}/man/mping.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
