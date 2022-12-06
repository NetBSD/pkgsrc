# $NetBSD: Makefile,v 1.1 2022/12/06 11:10:24 vins Exp $
#

DISTNAME=	joe-3.1jupp41
PKGNAME=	${DISTNAME:S/jupp/./:S/joe/jupp/}
CATEGORIES=	editors
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/jupp/ \
		http://pub.allbsd.org/MirOS/dist/jupp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.mirbsd.org/jupp.htm
COMMENT=	The portable version of joe from the MirOS project
LICENSE=	gnu-gpl-v1

CONFLICTS+=	joe-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/examples
CONFIGURE_ARGS+=	--disable-dependency-tracking

INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/applications

WRKSRC=		${WRKDIR}/jupp

post-install:
.for f in jmacs joe jpico jstar jupp
	${INSTALL_DATA} ${WRKSRC}/docs/${f}.png					\
		${DESTDIR}${PREFIX}/share/pixmaps/

	${INSTALL_DATA} ${FILESDIR}/${f}.desktop				\
		${DESTDIR}${PREFIX}/share/applications/
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
