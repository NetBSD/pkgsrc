# $NetBSD: Makefile,v 1.2 2011/01/24 21:51:06 ahoka Exp $

DISTNAME=	suse_fontconfig-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	fontconfig-2.8.0-7.1.${SUSE_ARCH}.rpm
PKGREVISION=	1

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for fontconfig

EMUL_MODULES.linux=	expat freetype2

.include "../../emulators/suse113_linux/Makefile.common"

PLIST_SRC=	${PKGDIR}/PLIST ${RPM2PKG_PLIST}

do-build:
	${SETENV} LOCALBASE=${LOCALBASE:Q} X11BASE=${X11BASE:Q}	\
	${AWK} -f ${FILESDIR}/generate.awk ${FILESDIR}/local.conf.in	\
		> ${WRKSRC}/local.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/local.conf				\
		${DESTDIR}${PREFIX}/${EMULSUBDIR}/etc/fonts/local.conf

.include "../../mk/bsd.pkg.mk"
