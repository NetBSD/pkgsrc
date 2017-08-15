# $NetBSD: Makefile,v 1.14 2017/08/15 13:55:17 adam Exp $

DISTNAME=	faac-1.29.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://faac.sourceforge.net/
COMMENT=	AAC audio encoder
LICENSE=	gnu-gpl-v2

RESTRICTED=		This software may require the payment of patent royalties
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && aclocal -I . && autoheader && libtoolize --automake \
	&& automake -a && autoconf

.include "../../mk/bsd.pkg.mk"
