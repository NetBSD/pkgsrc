# $NetBSD: Makefile,v 1.4 2001/11/17 06:36:14 itohy Exp $
#

DISTNAME=	audacity-src-0.96
PKGNAME=	audacity-0.96
CATEGORIES=	audio
MASTER_SITES=	http://prdownloads.sourceforge.net/audacity/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://audacity.sourceforge.net/
COMMENT=	audio editor

DEPENDS+=	wxGTK-[0-9]*:../../x11/wxGTK
DEPENDS+=	pth-[0-9]*:../../devel/pth
DEPENDS+=	id3lib-[0-9]*:../../audio/id3lib
DEPENDS+=	libmpeg3-[0-9]*:../../devel/libmpeg3
DEPENDS+=	lame>=3.89:../../audio/lame
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-xaudio --with-libmpeg3
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	yes

# XXX Internal compiler error with -O2
.if (${MACHINE_ARCH} == alpha)
CFLAGS=		-O
.endif

post-patch:
	${SED} "s|XXXHELPDIRXXX|${PREFIX}/share|" \
		<${WRKSRC}/Help.cpp >${WRKSRC}/Help.cpp.tmp \
	&& ${MV} ${WRKSRC}/Help.cpp.tmp ${WRKSRC}/Help.cpp
	${RM} -rf ${WRKSRC}/mpeg3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/audacity ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/audacity-help.htb ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
