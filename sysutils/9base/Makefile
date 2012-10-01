# $NetBSD: Makefile,v 1.16 2012/10/01 21:19:44 cheusov Exp $
#

DISTNAME=	9base-6
PKGREVISION=	2
PKGNAME=	9base-20100604
CATEGORIES=	sysutils shells
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tools.suckless.org/9base
COMMENT=	Port of various original plan9 tools
#LICENSE=	lucent-public-v1.02 AND mit

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

CONFLICTS=		rc-[0-9]*

PKG_SHELL=		bin/rc

.include "../../mk/bsd.prefs.mk"

# Darwin doesn't support static link.
# See http://developer.apple.com/library/mac/#qa/qa1118/_index.html
.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-static
.else
LDFLAGS+= -static
.endif

#XXX see http://gnats.netbsd.org/43228
.if !empty(MACHINE_PLATFORM:MNetBSD-5.[0-8]*)
BUILDLINK_TRANSFORM+=	rm:-static
.endif

PREFIX9P=	${PREFIX}/9base

MAKE_FLAGS+=	PREFIX=${PREFIX9P} \
		MANPREFIX=${PREFIX9P}/${PKGMANDIR}

SUBST_CLASSES+=		shebang
SUBST_STAGE.shebang=	pre-configure
SUBST_MESSAGE.shebang=	Fixing shebang
SUBST_FILES.shebang=	troff/tmac/sendcover
SUBST_FILES.shebang+=	troff/font/devutf/mkMAP
SUBST_SED.shebang=	-e 's,/bin/rc,${PREFIX9P}/bin/rc,'

INSTALLATION_DIRS=	${PREFIX9P}/share/examples/9base
MAKE_DIRS+=		${PREFIX9P}/etc

EGDIR=		${PREFIX9P}/share/examples/9base
CONF_FILES=	${EGDIR}/rcmain ${PREFIX9P}/etc/rcmain

post-extract:
	${LN} -s getcallerpc-x86_64.c ${WRKSRC}/lib9/getcallerpc-amd64.c

.include "../../mk/bsd.pkg.mk"
