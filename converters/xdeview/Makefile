# $NetBSD: Makefile,v 1.17 2001/05/05 19:51:13 jlam Exp $
# FreeBSD Id: Makefile,v 1.11 1998/02/24 21:43:45 jseger Exp
#

DISTNAME=	uudeview-0.5.13
PKGNAME=	xdeview-0.5.13
CATEGORIES=	converters
MASTER_SITES=	http://www.informatik.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.informatik.uni-frankfurt.de/~fp/uudeview/
COMMENT=	X11 program for uu/xx/Base64/BinHex de-/encoding

DEPENDS+=	tk>=8.3.2:../../x11/tk
DEPENDS+=	uulib-0.5.13:../../converters/uulib

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tcl="${LOCALBASE}" --enable-tk="${LOCALBASE}"
# Season to taste --- anything over tcl7.5
CONFIGURE_ENV=	LDFLAGS=-s\
		CPPFLAGS="-I${LOCALBASE}/include/ \
		          -I${LOCALBASE}/include/"

ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl

PORTDOCDIR=	${PREFIX}/share/doc/xdeview
DOCFILES=	${FILESDIR}/porting.notes ${WRKSRC}/HOWTO

post-install:
	@${ECHO_MSG} "===>  Copying documents to ${PORTDOCDIR}"
	@${INSTALL_DATA_DIR} ${PORTDOCDIR}
	${INSTALL_DATA} ${DOCFILES} ${PORTDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
