# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 21:02:15 martin Exp $
#

DISTNAME=	pulsar-0.1.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pulsar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://pulsar.sourceforge.net/
COMMENT=	Small, secure POP3 daemon, featuring native SSL support

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

MANCOMPRESSED=	yes

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
