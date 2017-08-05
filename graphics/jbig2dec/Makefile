# $NetBSD: Makefile,v 1.7 2017/08/05 08:03:05 nros Exp $

DISTNAME=	jbig2dec-0.13
PKGREVISION=	1
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
