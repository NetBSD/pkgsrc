# $NetBSD: Makefile,v 1.12 1999/01/30 23:18:45 agc Exp $
# FreeBSD Id: Makefile,v 1.11 1998/02/24 21:43:45 jseger Exp
#

DISTNAME=	uudeview-0.5.13
PKGNAME=	xdeview-0.5.13
CATEGORIES=	converters
MASTER_SITES=	http://www.informatik.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.informatik.uni-frankfurt.de/~fp/uudeview/

DEPENDS+=	tk-8.0p2:../../x11/tk80
DEPENDS+=	uulib-0.5.13:../../converters/uulib

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tcl="${LOCALBASE}" --enable-tk="${LOCALBASE}"
# Season to taste --- anything over tcl7.5
CONFIGURE_ENV=	LDFLAGS=-s \
		CPPFLAGS="-I${LOCALBASE}/include/tcl8.0 \
		          -I${LOCALBASE}/include/tk8.0"

ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl

PORTDOCDIR?=	share/doc/xdeview
DOCFILES=	${FILESDIR}/porting.notes ${WRKSRC}/HOWTO

post-install:
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	${INSTALL_MAN} ${DOCFILES} ${PREFIX}/${PORTDOCDIR}
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
