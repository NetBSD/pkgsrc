# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:17 wiz Exp $

PKGNAME=	suse_fontconfig-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	fontconfig-2.13.1-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	libfontconfig1-2.13.1-150400.1.4.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for fontconfig

EMUL_MODULES.linux=	expat freetype2

.include "../../emulators/suse15_linux/Makefile.common"

PLIST_SRC=	${PKGDIR}/PLIST ${RPM2PKG_PLIST}

do-build:
	${SETENV} LOCALBASE=${LOCALBASE:Q} X11BASE=${X11BASE:Q}	\
	${AWK} -f ${FILESDIR}/generate.awk ${FILESDIR}/local.conf.in	\
		> ${WRKSRC}/local.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/local.conf				\
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/fonts/local.conf

.include "../../mk/bsd.pkg.mk"
