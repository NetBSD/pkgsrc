# $NetBSD: Makefile,v 1.4 2012/02/19 05:10:11 obache Exp $
#

DISTNAME=	SPTK-3.5
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

PKG_DESTDIR_SUPPORT=	user-destdir

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
