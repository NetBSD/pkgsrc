# $NetBSD: Makefile,v 1.13 2010/01/29 18:08:25 joerg Exp $
#

DISTNAME=	hptools-src-3.0.8
PKGNAME=	hptools-3.0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.hpcalc.org/hp48/pc/programming/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hpcalc.org/hp48/pc/programming/
COMMENT=	SDK for Hewlett-Packard HP-48G/49G/39G/40G calculators
LICENSE=	hptools-license

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=	Redistribution of unmodified source only; resale prohibited.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/Hptools
GNU_CONFIGURE=	YES
CONFIGURE_DIRS=	support
BUILD_DIRS=	support
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	bin
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin

post-build:
	${CHMOD} ${SHAREMODE} ${WRKSRC}/doc/*

post-install:
	cd ${WRKSRC} \
	&& pax -rw -pam -s ',^doc,hptools,g' doc ${DESTDIR}${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
