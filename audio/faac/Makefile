# $NetBSD: Makefile,v 1.12 2012/09/11 23:59:31 asau Exp $
#

DISTNAME=	faac-1.28
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.audiocoding.com/
COMMENT=	AAC audio encoder

RESTRICTED=	This software may require the payment of patent royalties
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_LIBTOOL=	yes
USE_TOOLS+=	automake
GNU_CONFIGURE=	yes

LIBTOOLIZE=	${PREFIX}/bin/libtoolize

pre-configure:
	cd ${WRKSRC};						\
	${LIBTOOLIZE} --automake;				\
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
