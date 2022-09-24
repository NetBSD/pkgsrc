# $NetBSD: Makefile,v 1.22 2022/09/24 08:27:52 nia Exp $

DISTNAME=	9base-6
PKGNAME=	9base-20100604
PKGREVISION=	3
CATEGORIES=	sysutils shells
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tools.suckless.org/9base
COMMENT=	Port of various original plan9 tools
#LICENSE=	lucent-public-v1.02 AND mit

MAKE_JOBS_SAFE=		no

CONFLICTS=		rc-[0-9]*

PKG_SHELL=		bin/rc

# commits utter sins with sprintf() macros; glhf
FORTIFY_SUPPORTED=	no

CFLAGS.SunOS+=		-DPLAN9PORT
LDFLAGS.SunOS+=		-lsocket -lnsl

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
