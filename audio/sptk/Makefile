# $NetBSD: Makefile,v 1.7 2016/07/10 12:06:21 mef Exp $
#

DISTNAME=	SPTK-3.9
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sp-tk/}
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	SPTKref-${PKGVERSION_NOREV}.pdf
DISTFILES+=	SPTKexamples-${PKGVERSION_NOREV}.pdf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sp-tk.sourceforge.net/
COMMENT=	Suite of speech signal processing tools
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	csh:run

GNU_CONFIGURE_PREFIX=	${PREFIX}/SPTK
CONFIGURE_ENV+=		CSH=${CSH}
CONFIGURE_ARGS+=	--disable-da

INSTALLATION_DIRS+=	share/doc/sptk

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sptk
	${INSTALL_DATA} ${WRKDIR}/SPTKref-${PKGVERSION_NOREV}.pdf ${DESTDIR}${PREFIX}/share/doc/sptk
	${INSTALL_DATA} ${WRKDIR}/SPTKexamples-${PKGVERSION_NOREV}.pdf ${DESTDIR}${PREFIX}/share/doc/sptk

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
