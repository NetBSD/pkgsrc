# $NetBSD: Makefile,v 1.8 2002/08/31 02:42:48 wiz Exp $
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

USE_BUILDLINK2=	yes

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

.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"
.include "../../devel/libmpeg3/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
