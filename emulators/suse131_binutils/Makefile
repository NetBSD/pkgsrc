# $NetBSD: Makefile,v 1.1 2017/03/06 11:53:54 hauke Exp $

PKGNAME=	suse_binutils-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	binutils-2.23.2-8.1.2.${SUSE_ARCH}

MAINTAINER=	pkg-users@NetBSD.org
COMMENT=	Linux compatibility package for binutils

EMUL_MODULES.linux=	base

PLIST_SRC=	${RPM2PKG_PLIST}

post-install:
	${LN} -fs ld.bfd ${DESTDIR}${PREFIX}/${EMULSUBDIR}/usr/bin/ld

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
