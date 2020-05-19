# $NetBSD: Makefile,v 1.64 2020/05/19 10:13:49 nia Exp $

DISTNAME=	libetpan-1.9.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=dinhviethoa/}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://etpan.org/libetpan.html
COMMENT=	Really nice mail library
LICENSE=	modified-bsd

BDB_ACCEPTED=		db3 db4 db5 db6
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
USE_TOOLS+=		autoconf automake
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=1 ${SH} autogen.sh

LDFLAGS.SunOS+=		-lsocket -lnsl

PKGCONFIG_OVERRIDE+=	libetpan.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
