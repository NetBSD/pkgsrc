# $NetBSD: Makefile,v 1.4 2004/10/03 00:12:54 tv Exp $
#

DISTNAME=	pulsar-0.1.1
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pulsar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://pulsar.sourceforge.net/
COMMENT=	Small, secure POP3 daemon, featuring native SSL support

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

MANCOMPRESSED=	yes

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
