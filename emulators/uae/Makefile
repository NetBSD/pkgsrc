# $NetBSD: Makefile,v 1.10 2001/02/02 22:17:20 kristerw Exp $

DISTNAME=	uae-0.8.15
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freiburg.linux.de/pub/uae/sources/develop/

MAINTAINER=	kristerw@netbsd.org
HOMEPAGE=	http://www.freiburg.linux.de/~uae/

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

# Because using the gtk+ user interface requires a thread library
# we use a brute force method to avoid detection of gtk+.
CONFIGURE_ARGS+=	--enable-dga --enable-vidmode \
			--with-gtk-prefix=${WRKDIR}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

do-install:
.for FILE in readdisk uae
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/share/doc/uae
.for FILE in FAQ README
	${INSTALL_DATA} ${WRKSRC}/docs/${FILE} ${PREFIX}/share/doc/uae
.endfor

.include "../../mk/bsd.pkg.mk"
