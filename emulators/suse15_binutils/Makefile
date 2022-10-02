# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:17 wiz Exp $

PKGNAME=	suse_binutils-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	binutils-2.37-150100.7.37.1.${SUSE_ARCH}
RPMPKGS+=	libctf-nobfd0-2.37-150100.7.37.1.${SUSE_ARCH}
RPMPKGS+=	libctf0-2.37-150100.7.37.1.${SUSE_ARCH}

MAINTAINER=	pkg-users@NetBSD.org
COMMENT=	Linux compatibility package for binutils

EMUL_MODULES.linux=	base

PLIST_SRC=	${RPM2PKG_PLIST}

post-install:
	${LN} -fs ld.bfd ${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/bin/ld

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
