# $NetBSD: Makefile,v 1.2 2008/02/03 02:49:19 reed Exp $
#

# fix install so it uses ${prefix}

DISTNAME=	rtf2latex2eUnix1
PKGNAME=	rtf2latex2e-1.0fc2
CATEGORIES=	print textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rtf2latex2e/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://sourceforge.net/projects/rtf2latex2e/
COMMENT=	RTF to LaTeX2e converter

# ImageMagick is an optional component

WRKSRC=	${WRKDIR}/rtf2latex2eUnix-1.0fc1/
BUILD_DIRS=	Unix
CONFIGURE_DIRS=	Unix
GNU_CONFIGURE=	yes
MAKE_ENV+=	INSTALL_DIR=${PREFIX}/share/rtf2latex2e

INSTALLATION_DIRS+=	bin share/doc/rtf2latex2e share/rtf2latex2e

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2latex2e.bin ${PREFIX}/bin/rtf2latex2e
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/rtf2latex2e/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rtf2latex2e/
	${INSTALL_DATA} ${WRKSRC}/doc/rtf2LaTeX2eDoc.html ${PREFIX}/share/doc/rtf2latex2e/
	cd ${WRKSRC} && ${PAX} -rw pref ${PREFIX}/share/rtf2latex2e

# install other docs and examples too?

.include "../../mk/bsd.pkg.mk"
