# $NetBSD: Makefile,v 1.4 2010/02/12 00:10:15 joerg Exp $
#

# fix install so it uses ${prefix}

DISTNAME=	rtf2latex2eUnix1
PKGNAME=	rtf2latex2e-1.0fc2
CATEGORIES=	print textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rtf2latex2e/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://sourceforge.net/projects/rtf2latex2e/
COMMENT=	RTF to LaTeX2e converter

PKG_DESTDIR_SUPPORT=	user-destdir

# ImageMagick is an optional component

WRKSRC=	${WRKDIR}/rtf2latex2eUnix-1.0fc1/
BUILD_DIRS=	Unix
CONFIGURE_DIRS=	Unix
GNU_CONFIGURE=	yes
MAKE_ENV+=	INSTALL_DIR=${PREFIX}/share/rtf2latex2e

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	bin share/doc/rtf2latex2e share/rtf2latex2e

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2latex2e.bin ${DESTDIR}${PREFIX}/bin/rtf2latex2e
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/rtf2latex2e/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/rtf2latex2e/
	${INSTALL_DATA} ${WRKSRC}/doc/rtf2LaTeX2eDoc.html ${DESTDIR}${PREFIX}/share/doc/rtf2latex2e/
	cd ${WRKSRC} && pax -rw pref ${DESTDIR}${PREFIX}/share/rtf2latex2e

# install other docs and examples too?

.include "../../mk/bsd.pkg.mk"
