# $NetBSD: Makefile,v 1.6 2000/07/13 17:34:38 kristerw Exp $

DISTNAME=	uae-0.8.12
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freiburg.linux.de/pub/uae/

MAINTAINER=	kristerw@netbsd.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/

NOT_FOR_PLATFORM=	*-*-arm32

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

# Because using the gtk+ user interface requires a thread library
# we use a brute force method to avoid detection of gtk+.
CONFIGURE_ARGS+=	--enable-dga --enable-vidmode \
			--with-gtk-prefix=${WRKDIR}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

post-configure:
	(cd ${WRKSRC}/src; ${MAKE} .SECONDARY)

do-install:
.for FILE in readdisk uae
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/share/doc/uae
.for FILE in FAQ README
	${INSTALL_DATA} ${WRKSRC}/docs/${FILE} ${PREFIX}/share/doc/uae
.endfor

.include "../../mk/bsd.pkg.mk"
