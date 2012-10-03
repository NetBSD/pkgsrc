# $NetBSD: Makefile,v 1.21 2012/10/03 00:02:47 asau Exp $
#

DISTNAME=	zephyr-20010518
PKGREVISION=	7
CATEGORIES=	chat net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.mit.edu/olh/Zephyr/index.html
COMMENT=	Project Athena's original Instant Messaging system

WRKSRC=		${WRKDIR}/zephyr
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-I${BUILDLINK_PREFIX.kth-krb4}/include/kerberosIV
CPPFLAGS.NetBSD+=	-I${BUILDLINK_PREFIX.kth-krb4}/include/kerberosIV/ss
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-krb4
CONFIGURE_ARGS+=	--with-ares

ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

PKG_SYSCONFSUBDIR=	zephyr
OWN_DIRS=		${PKG_SYSCONFDIR}/acl
EGDIR=			${PREFIX}/share/examples/zephyr
CONF_FILES=		${EGDIR}/default.subscriptions \
			${PKG_SYSCONFDIR}/default.subscriptions

RCD_SCRIPTS=		zhm

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Fixing mandir in Makefile.in
SUBST_FILES.mandir=	*/*/Makefile.in */Makefile.in Makefile.in
SUBST_SED.mandir=	-e 's,$${prefix}/man,@mandir@,g'

.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	l:ss:ss:roken:crypt
.endif

.if ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
CFLAGS+=		-DHAVE_STRERROR
SUBST_CLASSES+=		FreeFly
SUBST_STAGE.FreeFly=	post-patch
SUBST_MESSAGE.FreeFly=	Replacing libdes with libcrypt + libcrypto
SUBST_FILES.FreeFly=	aclocal.m4 configure
SUBST_SED.FreeFly=	-e 's,-lkrb -ldes,-lkrb -lcrypt -lcrypto,g'
.else
CONFIGURE_ARGS+=	--with-hesiod
.endif

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${ZEPHYR_DOCDIR}
.for f in ${ZEPHYR_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${ZEPHYR_DOCDIR}
.endfor

.include "../../devel/readline/buildlink3.mk"
.include "../../net/hesiod/buildlink3.mk"
.include "../../net/libares/buildlink3.mk"
.include "../../security/kth-krb4/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
