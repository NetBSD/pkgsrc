# $NetBSD: Makefile,v 1.6 2003/10/06 11:35:31 jlam Exp $
#

DISTNAME=	metakit-2.4.8-38
PKGNAME=	metakit-lib-2.4.8
WRKSRC=		${WRKDIR}/metakit-2.4.8/builds
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/older/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+=	--with-tcl=
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK2=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/../include/mk4io.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
