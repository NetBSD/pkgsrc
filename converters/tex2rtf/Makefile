# $NetBSD: Makefile,v 1.5 2003/12/13 20:14:26 ben Exp $

DISTNAME=		tex2rtf164_source
PKGNAME=		tex2rtf-164
WRKSRC=			${WRKDIR}/src
CATEGORIES=		converters textproc
MASTER_SITES=		ftp://www.remstar.com/pub/wxwin/tex2rtf/	\
			ftp://ftp.sunet.se/pub7/lang/wxwin/tex2rtf/
EXTRACT_SUFX=		.zip

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://web.ukonline.co.uk/julian.smart/tex2rtf/
COMMENT=		LaTex-to-RTF translator

do-build:
	cd ${WRKSRC} && make -f makefile.unx nogui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tex2rtf_nogui ${PREFIX}/bin/tex2rtf

.include "../../mk/bsd.pkg.mk"
