# $NetBSD: Makefile,v 1.8 2004/03/29 05:19:47 ben Exp $

DISTNAME=		tex2rtf164_source
PKGNAME=		tex2rtf-164
CATEGORIES=		converters textproc
MASTER_SITES=		ftp://www.remstar.com/pub/wxwin/tex2rtf/	\
			ftp://ftp.sunet.se/pub7/lang/wxwin/tex2rtf/
EXTRACT_SUFX=		.zip

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.wxwindows.org/tex2rtf/index.htm
COMMENT=		LaTex-to-RTF translator

WRKSRC=			${WRKDIR}/src

do-build:
	cd ${WRKSRC} && make -f makefile.unx nogui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tex2rtf_nogui ${PREFIX}/bin/tex2rtf

.include "../../mk/bsd.pkg.mk"
