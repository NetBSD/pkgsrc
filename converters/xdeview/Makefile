# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:21 frueauf Exp $
# FreeBSD Id: Makefile,v 1.11 1998/02/24 21:43:45 jseger Exp
#

DISTNAME=	uudeview-0.5.13
PKGNAME=	xdeview-0.5.13
CATEGORIES=	converters
MASTER_SITES=	http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/ \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/

MAINTAINER=	packages@netbsd.org

LIB_DEPENDS=    tk80.1.:${PORTSDIR}/x11/tk80 \
		uu.1.:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tcl="${PREFIX}" --enable-tk="${PREFIX}"
# Season to taste --- anything over tcl7.5
CONFIGURE_ENV=	LDFLAGS=-s \
		CPPFLAGS="-I${PREFIX}/include/tcl8.0 -I${PREFIX}/include/tk8.0"

ALL_TARGET=	xdeview
INSTALL_TARGET=	install-tcl
MAN1=		xdeview.1

PORTDOCDIR?=	share/doc/xdeview
DOCFILES=	${FILESDIR}/porting.notes ${WRKSRC}/HOWTO

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	${INSTALL_MAN} ${DOCFILES} ${PREFIX}/${PORTDOCDIR}
.else
	@${ECHO_MSG} "===>  Not copying available documents"
.endif
	${INSTALL_MAN} ${WRKSRC}/man/xdeview.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
