# $NetBSD: Makefile,v 1.10 2007/08/23 20:43:42 jlam Exp $

DISTNAME=	suse_fontconfig-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for fontconfig

EMUL_MODULES.linux=	expat freetype2

.include "../../emulators/suse91_linux/Makefile.common"

do-build:
	${SETENV} LOCALBASE=${LOCALBASE:Q} X11PREFIX=${X11PREFIX:Q}	\
	${AWK} -f ${FILESDIR}/generate.awk ${FILESDIR}/local.conf.in	\
		> ${WRKSRC}/local.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/local.conf				\
		${PREFIX}/${EMULSUBDIR}/etc/fonts/local.conf

.include "../../mk/bsd.pkg.mk"
