# $NetBSD: Makefile,v 1.11 1998/08/14 23:14:08 tron Exp $
#

DISTNAME=	mtools-3.9.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/

PATCH_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/
PATCHFILES=	mtools-3.9.1-0907b.diff.gz

MAINTAINER=	is@netbsd.org

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INFO_FILES=	mtools.info

post-extract:
	@${LN} -s . ${WRKSRC}/mtools

post-patch:
	@${RM} ${WRKSRC}/mtools

.include "../../mk/bsd.pkg.mk"
