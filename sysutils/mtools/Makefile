# $NetBSD: Makefile,v 1.14 1998/08/20 15:17:27 tsarna Exp $
#

DISTNAME=	mtools-3.9.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/

PATCH_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/
PATCHFILES=	mtools-3.9.1-0907b.diff.gz

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www.tux.org/pub/knaff/mtools/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INFO_FILES=	mtools.info

pre-patch:
	@${LN} -s . ${WRKSRC}/mtools

post-patch:
	@${RM} ${WRKSRC}/mtools

.include "../../mk/bsd.pkg.mk"
