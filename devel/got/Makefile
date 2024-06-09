# $NetBSD: Makefile,v 1.9 2024/06/09 13:25:05 vins Exp $

DISTNAME=	got-portable-0.100
PKGNAME=	${DISTNAME:S/-portable//}
CATEGORIES=	devel
MASTER_SITES=	https://gameoftrees.org/releases/portable/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://gameoftrees.org/index.html
COMMENT=	Game of Trees VCS to manipulate git repositories
LICENSE=	isc

CONFLICTS+=	got-portable-[0-9]*
SUPERSEDES+=	got-portable-[0-9]*
PREV_PKGPATH=	devel/got-portable

BUILD_DEFS+=	VARBASE

USE_TOOLS+=	pkg-config yacc ksh:test perl:test
# required for waddwstr(3)
USE_NCURSES=	yes

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

# Tests for HTTP protocol support rely on the HTTP::Daemon Perl module.
TEST_DEPENDS+=		p5-HTTP-Daemon-[0-9]*:../../www/p5-HTTP-Daemon
TEST_DEPENDS+=		git-[0-9]*:../../devel/git
INTERACTIVE_STAGE+=	test
TEST_TARGET=		tests

REPLACE_KSH+=	regress/gotd/repo_write_protected.sh
REPLACE_KSH+=	regress/tog/log.sh

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

SUBST_CLASSES+=		ncursesw
SUBST_STAGE.ncursesw=	pre-configure
SUBST_MESSAGE.ncursesw=	Do not check for ncursesw on NetBSD
SUBST_FILES.ncursesw=	configure
SUBST_SED.ncursesw+=	-e "s:gnupanelw:gnupanel:g"

MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q}

.include "../../mk/bsd.prefs.mk"

post-extract:
	${RUN}cp ${FILESDIR}/README.pkgsrc ${WRKSRC}

.if ${OPSYS} == "Linux"
post-patch:
# let libmd include the correct header.
	${RUN}${RM} -f ${WRKSRC}/compat/sha2.h
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/gotd.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|} ${DESTDIR}${DOCDIR}

# needs libtls
.include "../../security/libretls/buildlink3.mk"

# needs gnupanelw
BUILDLINK_API_DEPENDS.ncurses+=   ncurses>=6.5
.include "../../devel/ncurses/buildlink3.mk"

# compatibility macros and functions for Linux.
.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
