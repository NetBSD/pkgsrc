# $NetBSD: Makefile,v 1.6 2023/10/24 22:09:48 wiz Exp $

DISTNAME=	filter-dkimsign-0.6
PKGREVISION=	2
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail
MASTER_SITES=	https://imperialat.at/releases/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://imperialat.at/dev/filter-dkimsign/
COMMENT=	OpenSMTPD filter integration for signing mail with DKIM
LICENSE=	isc

USE_TOOLS+=	gmake

DEPENDS+=	opensmtpd-[0-9]*:../../mail/opensmtpd

CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE   # strtonum()

LD_ADD=		-lcrypto -lopensmtpd
LDFLAGS+=	${COMPILER_RPATH_FLAG}${SSLBASE}/lib -L${SSLBASE}/lib
LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libopensmtpd}/lib
LDFLAGS+=	-L${BUILDLINK_PREFIX.libopensmtpd}/lib ${LD_ADD}

PKG_GROUPS=		_dkimsign
PKG_USERS=		_dkimsign:_dkimsign
PKG_GECOS._smtpd=	OpenSMTPD DKIM signer
PKG_HOME._smtpd=	${PKG_SYSCONFDIR}/smtpd/dkim

OWN_DIRS+=	${PKG_SYSCONFDIR}/smtpd/dkim

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	README.dkim
SUBST_VARS.prefix=	PKG_SYSCONFDIR PREFIX
SUBST_MESSAGE.prefix=	Replacing pkgsrc placeholders.

MAKE_FILE=	Makefile.gnu
MAKE_ENV+=	LOCALBASE=${PREFIX:Q}
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man3
MAKE_ENV+=	MANFORMAT=man
MAKE_ENV+=	HAVE_ED25519=1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "OpenBSD"
MAKE_ENV+=	NEED_PLEDGE=1
.  if ${OPSYS} == "SunOS" && ${OPSYS_VERSION} >= 051100
MAKE_ENV+=	NEED_RECALLOCARRAY=0
.  else
MAKE_ENV+=	NEED_RECALLOCARRAY=1
.  endif
.endif

MAKE_ENV.NetBSD+=	NEED_EXPLICIT_BZERO=1
MAKE_ENV.Darwin+=	NEED_STRTONUM=1
MAKE_ENV.Linux+=	NEED_STRLCAT=1
MAKE_ENV.Linux+=	NEED_STRLCPY=1
MAKE_ENV.Linux+=	NEED_STRTONUM=1
MAKE_ENV.Linux+=	NEED_EXPLICIT_BZERO=1
MAKE_ENV.Linux+=	NEED_REALLOCARRAY=1

INSTALL_ENV=		INSTALL=${INSTALL:Q}
INSTALLATION_DIRS+=	libexec/opensmtpd ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/doc/opensmtpd/filters

post-extract:
	${RUN}${CP} ${FILESDIR}/README.dkim ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.dkim	\
		${DESTDIR}${PREFIX}/share/doc/opensmtpd/filters

.include "../../devel/libopensmtpd/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
