# $NetBSD: Makefile,v 1.7 2002/07/22 09:54:05 agc Exp $
#

DISTNAME=	audacity-src-0.96
PKGNAME=	audacity-0.96
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audacity/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://audacity.sourceforge.net/
COMMENT=	audio editor

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-xaudio --with-libmpeg3
USE_GMAKE=	yes

USE_BUILDLINK_ONLY=	yes

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

.include "../../audio/id3lib/buildlink.mk"
.include "../../audio/lame/buildlink.mk"
.include "../../devel/libmpeg3/buildlink.mk"
.include "../../x11/wxGTK/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
