# $NetBSD: Makefile,v 1.1.1.1 1999/06/19 14:38:08 tron Exp $

DISTNAME=	uae-0.8.8
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freiburg.linux.de/pub/uae/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

CPPFLAGS=		-I${WRKSRC}/src/include
# Because using the gtk+ user interfaces requires a thread library
# we use a brute force method to avoid detection of gtk+.
CONFIGURE_ARGS+=	--enable-dga --enable-vidmode \
			--with-gtk-prefix=${WRKDIR}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

post-extract:
	@${MKDIR} ${WRKSRC}/src/include/machine
	@${LN} -sf /usr/include/soundcard.h ${WRKSRC}/src/include/machine

do-install:
.for FILE in readdisk uae
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/share/doc/uae
.for FILE in FAQ README
	${INSTALL_DATA} ${WRKSRC}/docs/${FILE} ${PREFIX}/share/doc/uae
.endfor

.include "../../mk/bsd.pkg.mk"
