# $NetBSD: Makefile,v 1.1.1.1 2002/12/11 12:11:11 cjep Exp $
#

DISTNAME=	hptools-src-3.0.8
PKGNAME=	hptools-3.0.8
WRKSRC=		${WRKDIR}/Hptools/support
CATEGORIES=	devel
MASTER_SITES=	http://www.epita.fr/~avenar_j/hp/product/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://etud.epita.fr:8000/~avenar_j/hp/calcen.html
COMMENT=	SDK for Hewlett-Packard HP-48G/49G/39G/40G calculators

RESTRICTED=	"Redistribution of unmodified source only; resale prohibited."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
LICENSE=	hptools-license

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

post-build:
	${CHMOD} ${SHAREMODE} ${WRKSRC}/../doc/*

post-install:
	cd ${WRKSRC}/.. \
	&& ${PAX} -rw -pam -s ',^doc,hptools,g' doc ${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
