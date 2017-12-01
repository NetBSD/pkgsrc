# $NetBSD: Makefile,v 1.15 2017/12/01 11:00:03 adam Exp $

DISTNAME=	faac-1.29.9.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

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
