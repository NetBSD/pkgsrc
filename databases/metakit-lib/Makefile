# $NetBSD: Makefile,v 1.1.1.1 2002/12/04 18:47:15 drochner Exp $
#

DISTNAME=	metakit-2.4.8-38
PKGNAME=	metakit-lib-2.4.8
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	embedded database library

WRKSRC=		${WRKDIR}/metakit-2.4.8/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+=	--with-tcl=
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK2=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/../include/mk4io.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
