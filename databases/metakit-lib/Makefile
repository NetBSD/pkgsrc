# $NetBSD: Makefile,v 1.8 2004/02/14 17:21:36 jlam Exp $
#

DISTNAME=	metakit-2.4.8-38
PKGNAME=	metakit-lib-2.4.8
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/older/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

WRKSRC=		${WRKDIR}/metakit-2.4.8/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+=	--with-tcl=
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/../include/mk4io.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
