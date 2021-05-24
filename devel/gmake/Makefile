# $NetBSD: Makefile,v 1.115 2021/05/24 19:49:57 wiz Exp $

DISTNAME=	make-4.3
PKGNAME=	g${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=make/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/make/make.html
COMMENT=	GNU version of 'make' utility
LICENSE=	gnu-gpl-v3

USE_FEATURES=		snprintf

GNU_CONFIGURE=		yes
TEXINFO_REQD+=		4.0
INFO_FILES=		yes

TEST_TARGET=		check
USE_TOOLS+=		perl:test

CONFIGURE_ARGS+=	--program-prefix=g

# workaround for broken strndup
CONFIGURE_ARGS.MirBSD+=	ac_cv_func_strndup=no

# XXX: Do not install gmake setgid and do not override the owner group
# XXX: based on possible /dev/kmem permissions.
CONFIGURE_ARGS+=	ac_cv_func_getloadavg_setgid=no

.include "../../mk/bsd.prefs.mk"

# kernel bug, fixed in NetBSD 9.99.82
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-9].*)
CONFIGURE_ARGS.NetBSD+=	--disable-posix-spawn
.endif

AUTO_MKDIRS=		yes

.include "options.mk"

post-install:
	${LN} -sf ${PREFIX}/bin/gmake ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/make
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gmake.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/make.1

.include "../../mk/bsd.pkg.mk"
