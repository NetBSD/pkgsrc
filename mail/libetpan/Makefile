# $NetBSD: Makefile,v 1.47 2017/05/14 14:36:22 wiz Exp $

DISTNAME=	libetpan-1.8
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=dinhviethoa/}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://etpan.org/libetpan.html
COMMENT=	Really nice mail library
LICENSE=	modified-bsd

BDB_ACCEPTED=		db3 db4 db5 db6
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
USE_TOOLS+=		autoconf automake

pre-configure:
	cd ${WRKSRC} && \
	libtoolize --force --copy && \
	aclocal -I m4 && \
	autoheader && \
	autoconf && \
	automake --add-missing --foreign --force --copy

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	libetpan-config.in
SUBST_SED.conf=		-e "s|@COMPILERFLAGS@|${COMPILER_RPATH_FLAG}|g"
SUBST_MESSAGE.conf=	Fixing libetpan-config.

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
