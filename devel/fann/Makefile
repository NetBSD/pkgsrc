# $NetBSD: Makefile,v 1.1.1.1 2006/10/04 20:12:34 gdt Exp $
#

DISTNAME=		fann-2.0.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fann/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://leenissen.dk/fann/
COMMENT=		Fast Artificial Neural Network

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	fann.pc.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fann
	(cd ${WRKSRC} && ${INSTALL_DATA} doc/* ${PREFIX}/share/doc/fann)

.include "../../mk/bsd.pkg.mk"
