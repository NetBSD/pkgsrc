# $NetBSD: Makefile,v 1.9 2004/04/16 15:39:26 drochner Exp $
#

DISTNAME=	metakit-2.4.9.3
PKGNAME=	metakit-lib-2.4.9.3
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.equi4.com/metakit/
COMMENT=	Embedded database library

WRKSRC=		${WRKDIR}/metakit-2.4.9.3/builds
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT= ../unix/configure
CONFIGURE_ARGS+=	--without-tcl
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/../include/mk4io.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
