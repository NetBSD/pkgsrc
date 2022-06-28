# $NetBSD: Makefile,v 1.120 2022/06/28 11:31:44 wiz Exp $

DISTNAME=	make-4.3
PKGNAME=	g${DISTNAME}
PKGREVISION=	4
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

#
# Keep in sync with devel/bmake, the goal is to ensure we use the same shell
# that was selected by bootstrap.
#
.if ${TOOLS_PLATFORM.sh:M?*/bin/mksh}
DEPENDS+=	mksh-[0-9]*:../../shells/mksh
CPPFLAGS+=	-DPKGSRC_DEFAULT_SHELL="\"${PREFIX}/bin/mksh\""
.elif ${TOOLS_PLATFORM.sh:M?*/bin/pdksh}
DEPENDS+=	pdksh-[0-9]*:../../shells/pdksh
CPPFLAGS+=	-DPKGSRC_DEFAULT_SHELL="\"${PREFIX}/bin/pdksh\""
.elif ${OPSYS} == "SunOS" && exists(/usr/bin/bash)
CPPFLAGS+=	-DPKGSRC_DEFAULT_SHELL="\"/usr/bin/bash\""
.endif

# kernel bug, fixed in NetBSD 9.99.82
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099982
CONFIGURE_ARGS.NetBSD+=	--disable-posix-spawn
.endif

.include "options.mk"

AUTO_MKDIRS=		yes

post-install:
	${LN} -sf ${PREFIX}/bin/gmake ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/make
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gmake.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/make.1

.include "../../mk/bsd.pkg.mk"
