# $NetBSD: Makefile,v 1.10 1998/08/14 23:11:20 tron Exp $
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
	@ln -s . ${WRKSRC}/mtools

post-patch:
	@rm ${WRKSRC}/mtools

.include "../../mk/bsd.pkg.mk"
