# $NetBSD: Makefile,v 1.28 2013/05/31 12:41:58 wiz Exp $
#

DISTNAME=		skey-1.1.5
PKGREVISION=		6
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONF_FILES+=		${PREFIX}/share/examples/skey/skeykeys \
			${PKG_SYSCONFDIR}/skeykeys

REPLACE_PERL=		skeyprune.pl

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

.include "../../mk/bsd.prefs.mk"

# PR#40434
.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		ac_cv_header_md4_h=no
CONFIGURE_ENV+=		ac_cv_header_sha1_h=no
BUILDLINK_TRANSFORM+=	l:crypt:md5:crypt
.endif
# PR#44324
.if ${OPSYS} == "DragonFly"
CONFIGURE_ENV+=		ac_cv_header_rmd160_h=no
.endif
.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
BUILDLINK_TRANSFORM+=	l:crypt:md:crypt
.endif
# setusercontext() is in -lutil
LIBS.DragonFly+=	-lutil
LIBS.FreeBSD+=		-lutil
LIBS.NetBSD+=		-lutil

post-install:
	${RANLIB} ${DESTDIR}${PREFIX}/lib/libskey.a

.include "../../mk/bsd.pkg.mk"
