# $NetBSD: Makefile,v 1.18 2026/09/02 18:47:29 maya Exp $
#

DISTNAME=	unfs3-0.11.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=unfs3/}
GITHUB_PROJECT=	unfs3
GITHUB_TAG=	refs/tags/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://unfs3.github.io/
COMMENT=	Userspace NFSv3 server
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

USE_TOOLS+=	flex:run bison autoconf automake pkg-config gmake
USE_LANGUAGES=	c

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "../../devel/libtirpc/builtin.mk"

.if ${USE_BUILTIN.libtirpc:Uno} == "yes"
CONFIGURE_ENV+=	TIRPC_CFLAGS=-I/usr/include
CONFIGURE_ENV+=	TIRPC_LIBS=-lc
.endif

.include "../../mk/bsd.prefs.mk"

CONF_FILES+=		${PREFIX}/share/examples/unfs3/exports \
				${PKG_SYSCONFDIR}/exports
RCD_SCRIPTS=		unfsd

INSTALLATION_DIRS+=	share/examples/unfs3

SUBST_CLASSES+=		exports
SUBST_STAGE.exports=	pre-configure
SUBST_MESSAGE.exports=	Fixing path to exports(5)
SUBST_FILES.exports=	daemon.c unfsd.8
SUBST_SED.exports=	-e 's,/etc/exports,${PKG_SYSCONFDIR}/exports,g'

pre-configure:
	cd ${WRKSRC} && autoupdate
	cd ${WRKSRC} && autoreconf -fiv

post-install:
	${INSTALL_DATA} ${FILESDIR}/exports \
		${DESTDIR}${PREFIX}/share/examples/unfs3

.include "../../devel/libtirpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
