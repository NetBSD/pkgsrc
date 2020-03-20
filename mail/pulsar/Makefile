# $NetBSD: Makefile,v 1.23 2020/03/20 11:57:59 nia Exp $
#

DISTNAME=	pulsar-0.1.1
PKGREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pulsar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://pulsar.sourceforge.net/
COMMENT=	Small, secure POP3 daemon, featuring native SSL support

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake

CFLAGS.SunOS+=	-Du_int32_t=uint32_t
LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
