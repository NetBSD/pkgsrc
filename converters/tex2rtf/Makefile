# $NetBSD: Makefile,v 1.15 2005/06/16 06:57:43 jlam Exp $

DISTNAME=		tex2rtf-2.01-source
PKGNAME=		tex2rtf-2.01
PKGREVISION=	2
CATEGORIES=		converters textproc
MASTER_SITES=		ftp://biolpc22.york.ac.uk/pub/tex2rtf/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.wxwidgets.org/tex2rtf/index.htm
COMMENT=		LaTex-to-RTF translator

WRKSRC=			${WRKDIR}/${DISTNAME}/src
MAKEFILE=		makefile.unx
USE_LANGUAGES=		c++
INSTALLATION_DIRS=	bin

post-patch:
	${CP} ${FILESDIR}/stringmatch.* ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tex2rtf ${PREFIX}/bin/tex2rtf

.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
