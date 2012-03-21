# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:36:25 obache Exp $

DISTNAME=	suse_fontconfig-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	fontconfig-2.8.0-24.14.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for fontconfig

EMUL_MODULES.linux=	expat freetype2

.include "../../emulators/suse121_linux/Makefile.common"

PLIST_SRC=	${PKGDIR}/PLIST ${RPM2PKG_PLIST}

do-build:
	${SETENV} LOCALBASE=${LOCALBASE:Q} X11BASE=${X11BASE:Q}	\
	${AWK} -f ${FILESDIR}/generate.awk ${FILESDIR}/local.conf.in	\
		> ${WRKSRC}/local.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/local.conf				\
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/fonts/local.conf

.include "../../mk/bsd.pkg.mk"
