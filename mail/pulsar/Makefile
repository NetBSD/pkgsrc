# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:22 tv Exp $
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
USE_GNU_TOOLS+=	make

MANCOMPRESSED=	yes

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
