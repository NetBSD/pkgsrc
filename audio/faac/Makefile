# $NetBSD: Makefile,v 1.17 2019/06/23 11:41:25 nia Exp $

DISTNAME=	faac-1.29.9.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://faac.sourceforge.net/
COMMENT=	AAC audio encoder
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake
GNU_CONFIGURE=		yes

# https://gcc.gnu.org/bugzilla/show_bug.cgi?id=52624
GCC_REQD+=		4.8

pre-configure:
	cd ${WRKSRC} && aclocal -I . && autoheader && libtoolize --automake \
	&& automake -a && autoconf

.include "../../mk/bsd.pkg.mk"
