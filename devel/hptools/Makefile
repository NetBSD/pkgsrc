# $NetBSD: Makefile,v 1.10 2007/11/18 10:39:57 wiz Exp $
#

DISTNAME=	hptools-src-3.0.8
PKGNAME=	hptools-3.0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.hpcalc.org/hp48/pc/programming/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hpcalc.org/hp48/pc/programming/
COMMENT=	SDK for Hewlett-Packard HP-48G/49G/39G/40G calculators

RESTRICTED=	Redistribution of unmodified source only; resale prohibited.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
LICENSE=	hptools-license

WRKSRC=		${WRKDIR}/Hptools
GNU_CONFIGURE=	YES
CONFIGURE_DIRS=	support
BUILD_DIRS=	support

post-build:
	${CHMOD} ${SHAREMODE} ${WRKSRC}/doc/*

post-install:
	cd ${WRKSRC} \
	&& ${PAX} -rw -pam -s ',^doc,hptools,g' doc ${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
