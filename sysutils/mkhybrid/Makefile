# $NetBSD: Makefile,v 1.11 2001/02/17 17:42:16 wiz Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/06/16 16:50:06 dburr Exp
#

DISTNAME=	mkhybrid-1.12b5.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.ge.ucl.ac.uk/pub/mkhfs/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ps.ucl.ac.uk/~jcpearso/mkhybrid.html
COMMENT=	create a hybrid ISO9660/JOLIET/HFS/Rock Ridge filesystem

GNU_CONFIGURE=	yes
CFLAGS+=	-Dunix
TBL?=		tbl
ALL_TARGET=	World

post-extract:
		@cd ${WRKSRC}; \
		${MV} mkhybrid.8 mkhybrid.tbl

post-build:
		${TBL} ${WRKSRC}/mkhybrid.tbl > ${WRKSRC}/mkhybrid.8

.include "../../mk/bsd.pkg.mk"
