# $NetBSD: Makefile,v 1.16 2024/01/15 19:41:19 vins Exp $

DISTNAME=	got-portable-0.95
CATEGORIES=	devel
MASTER_SITES=	https://gameoftrees.org/releases/portable/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://gameoftrees.org/portable.html
COMMENT=	Game of Trees version control system manipulating Git repo
LICENSE=	isc

CONFLICTS+=		got-[0-9]*

ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	Darwin-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

BUILD_DEFS+=	VARBASE

USE_TOOLS+=	pkg-config yacc

PKG_GROUPS=		_gotd
PKG_USERS=		_gotd:_gotd
PKG_GECOS._gotd=	Game of Trees Daemon
PKG_SHELL._gotd=	/sbin/nologin
PKG_HOME._gotd=		/nonexistent

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		YACC=${YACC:Q}
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:Q}
CONFIGURE_ENV+=		LDFLAGS=${LDFLAGS:Q}
CONFIGURE_ARGS+=	--enable-gotd
CONFIGURE_ARGS+=	--enable-cvg
CONFIGURE_ARGS+=	--with-gotd-empty-path=${VARBASE}/empty
CONFIGURE_ARGS+=	--with-gitwrapper-git-libexec-path=${PREFIX}/libexec/git-core

EGDIR=		${PREFIX}/share/examples/got
CONF_FILES+=	${EGDIR}/gotd.conf ${PKG_SYSCONFDIR}/gotd.conf

DOCDIR=		${PREFIX}/share/doc/got
PKG_DOCS=	CHANGELOG README README.pkgsrc README.portable TODO

MAKE_DIRS+=	${VARBASE}/empty ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

INSTALLATION_DIRS=	bin libexec
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	share/doc/got share/examples/got

RCD_SCRIPTS=	gotd
PKG_SHELL=	bin/gotsh

TEST_TARGET=	tests

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	README.pkgsrc
SUBST_VARS.pkgsrc=	PKG_SYSCONFDIR PREFIX VARBASE
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders.

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Fix configuration file path.
SUBST_FILES.conf+=	gitwrapper/gitwrapper.1 gotd/gotd.conf.5	\
			gotd/gotd.h gotd/gotd.8
SUBST_SED.conf+=	-e "s:/etc/gotd.conf:${PKG_SYSCONFDIR}/gotd.conf:g"

MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q}

.include "../../mk/bsd.prefs.mk"

post-extract:
	${RUN}cp ${FILESDIR}/README.pkgsrc ${WRKSRC}

.if ${OPSYS} == "Linux"
post-patch:
# let libmd include the correct header.
	${RM} -f ${WRKSRC}/compat/sha2.h
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/gotd.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|} ${DESTDIR}${DOCDIR}

# need libcrypto.so.1.1
BUILDLINK_API_DEPENDS.openssl+=   openssl>=1.1.1d
.include "../../security/openssl/buildlink3.mk"

# required for set_panel_userptr(3) and waddwstr(3).
.include "../../devel/ncursesw/buildlink3.mk"

# compatibility macros and functions for Linux.
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
