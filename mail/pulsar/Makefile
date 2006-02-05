# $NetBSD: Makefile,v 1.9 2006/02/05 23:09:57 joerg Exp $
#

DISTNAME=	pulsar-0.1.1
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pulsar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://pulsar.sourceforge.net/
COMMENT=	Small, secure POP3 daemon, featuring native SSL support

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake

MANCOMPRESSED=	yes

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../devel/sysexits/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
