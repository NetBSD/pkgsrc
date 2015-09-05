# $NetBSD: Makefile,v 1.5 2015/09/05 19:41:34 adam Exp $

DISTNAME=	jbig2dec-0.12
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.ghostscript.com/public/jbig2dec/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ghostscript.com/jbig2dec.html
COMMENT=	JBIG2 decoder library
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake
GNU_CONFIGURE=		yes

# we need this, because someone has left wrong symbolic links within the distfile
pre-configure:
	set -e; cd ${WRKSRC}; libtoolize -f; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
