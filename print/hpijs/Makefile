# $NetBSD: Makefile,v 1.11 2004/04/24 22:46:11 jlam Exp $

DISTNAME=	hpijs-1.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hpinkjet/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hpinkjet.sourceforge.net/
COMMENT=	HP inkjet printer driver server

CONFLICTS=	ghostscript<=6.0.1nb4 ghostscript-nox11<=6.0.1nb4

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CPPFLAGS+=		-DAPDK_BUFFER_SEND

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_PKGSRC_GCC=		# defined
.endif

do-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/ppd
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/html/hpijs
	cd ${WRKSRC} && ${CP} hpijs ${LOCALBASE}/bin/hpijs
	cd ${WRKSRC} && ${CP} hpijs_readme.html gs_hpijs.png \
		 ${LOCALBASE}/share/doc/html/hpijs/
	cd ${WRKSRC} && ${CP} ppd/HP* ${LOCALBASE}/share/ppd/
	${GZIP_CMD} ${LOCALBASE}/share/ppd/HP*.ppd

.include "../../mk/bsd.pkg.mk"
