# $NetBSD: Makefile,v 1.32 2016/02/26 09:41:06 jperkin Exp $
#

DISTNAME=		skey-1.1.5
PKGREVISION=		8
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
#MASTER_SITES=		ftp://ftp.math.ethz.ch/hg/pub/opie/
#DIST_SUBDIR=		skey-1.1.5
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/weiyeh/skey
COMMENT=		Port of OpenBSD s/key implementation

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONF_FILES+=		${PREFIX}/share/examples/skey/skeykeys \
			${PKG_SYSCONFDIR}/skeykeys

REPLACE_PERL=		skeyprune.pl

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

# PR#40434
CONFIGURE_ENV.SunOS+=		ac_cv_header_md4_h=no
CONFIGURE_ENV.SunOS+=		ac_cv_header_sha1_h=no
BUILDLINK_TRANSFORM.SunOS+=	l:crypt:md5:crypt

# PR#44324
CONFIGURE_ENV.DragonFly+=	ac_cv_header_rmd160_h=no

BUILDLINK_TRANSFORM.DragonFly+=	l:crypt:md:crypt
BUILDLINK_TRANSFORM.FreeBSD+=	l:crypt:md:crypt

# setusercontext() is in -lutil
LIBS.DragonFly+=	-lutil
LIBS.FreeBSD+=		-lutil
LIBS.NetBSD+=		-lutil

post-install:
	${RANLIB} ${DESTDIR}${PREFIX}/lib/libskey.a

.include "../../mk/bsd.pkg.mk"
