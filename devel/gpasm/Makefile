# $NetBSD: Makefile,v 1.2 2001/07/05 14:32:33 dmcmahill Exp $

DISTNAME=	gpasm-0.9.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/gpasm/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=       http://gpasm.sourceforge.net/
COMMENT=	assembler for Microchip's PIC micro-processors

DEPENDS+=	bison>=1.28:../../devel/bison

GNU_CONFIGURE=  yes
USE_GMAKE=      yes

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gpasm
		for i in `ls ${WRKSRC}/doc/gpasm.*`; do \
		  ${INSTALL_DATA} $$i ${PREFIX}/share/doc/gpasm; \
		done

.include "../../mk/bsd.pkg.mk"
