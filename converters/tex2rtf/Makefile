# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:42:52 jlam Exp $

DISTNAME=		tex2rtf164_source
PKGNAME=		tex2rtf-164
CATEGORIES=		converters textproc
MASTER_SITES=		ftp://www.remstar.com/pub/wxwin/tex2rtf/	\
			ftp://ftp.sunet.se/pub7/lang/wxwin/tex2rtf/
EXTRACT_SUFX=		.zip

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://web.ukonline.co.uk/julian.smart/tex2rtf/
COMMENT=		LaTex-to-RTF translator

WRKSRC=			${WRKDIR}/src

do-build:
	cd ${WRKSRC} && make -f makefile.unx nogui

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tex2rtf_nogui ${PREFIX}/bin/tex2rtf

.include "../../mk/bsd.pkg.mk"
