# $NetBSD: Makefile,v 1.24 2011/01/06 08:55:37 obache Exp $
#

DISTNAME=		skey-1.1.5
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

PKG_DESTDIR_SUPPORT=	user-destdir

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

post-install:
	${RANLIB} ${DESTDIR}${PREFIX}/lib/libskey.a

.include "../../mk/bsd.pkg.mk"
