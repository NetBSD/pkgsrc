# $NetBSD: Makefile,v 1.1.1.1 2011/05/02 11:57:16 obache Exp $
#

DISTNAME=	SPTK-3.4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sp-tk/}
DISTFILES=	${DEFAULT_DISTFILES} SPTKref-3.4.pdf SPTKexamples-3.4.pdf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sp-tk.sourceforge.net/
COMMENT=	Suite of speech signal processing tools
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

GNU_CONFIGURE_PREFIX=	${PREFIX}/SPTK

INSTALLATION_DIRS+=	share/doc/sptk

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/sptk
	${INSTALL_DATA} ${WRKDIR}/SPTKref-3.4.pdf ${DESTDIR}${PREFIX}/share/doc/sptk
	${INSTALL_DATA} ${WRKDIR}/SPTKexamples-3.4.pdf ${DESTDIR}${PREFIX}/share/doc/sptk

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
