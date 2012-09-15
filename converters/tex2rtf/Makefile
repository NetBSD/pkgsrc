# $NetBSD: Makefile,v 1.35 2012/09/15 10:04:00 obache Exp $

DISTNAME=		tex2rtf-2.01-source
PKGNAME=		tex2rtf-2.01
PKGREVISION=		18
CATEGORIES=		converters textproc
MASTER_SITES=		ftp://biolpc22.york.ac.uk/pub/tex2rtf/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.wxwidgets.org/tex2rtf/index.htm
COMMENT=		LaTex-to-RTF translator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src
MAKE_FILE=		makefile.unx
USE_LANGUAGES=		c++
INSTALLATION_DIRS=	bin

post-patch:
	${CP} ${FILESDIR}/stringmatch.* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tex2rtf ${DESTDIR}${PREFIX}/bin/tex2rtf

.include "../../x11/wxGTK26/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
