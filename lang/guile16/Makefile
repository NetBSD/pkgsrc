# $NetBSD: Makefile,v 1.13 2013/10/18 16:05:06 roy Exp $

DISTNAME=		guile-1.6.8
PKGREVISION=		6
PKGNAME=		guile16-1.6.8
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension (1.6.x series)

# Purposely not defining PREV_PKGPATH
SUPERSEDES=		guile-1.6.*

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/1.6
USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		YES
PTHREAD_AUTO_VARS=	YES
INFO_FILES=		yes

TEST_DIRS=		${WRKSRC}
TEST_TARGET=		check
OWN_DIRS=		${PREFIX}/share/guile/site

BUILDLINK_PASSTHRU_DIRS+=	${GNU_CONFIGURE_PREFIX}

# Without doing this, guile is unable to load its shared modules on
# at least SunOS-5.9/sparc and maybe others.
# Loading of modules can be verified by running
# ${GNU_CONFIGURE_PREFIX}/bin/guile
# and at the guile> prompt:
# (load-extension "libguile-srfi-srfi-13-14-v-1" "scm_init_srfi_13")
LDFLAGS+=			${COMPILER_RPATH_FLAG}${GNU_CONFIGURE_PREFIX}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CPPFLAGS+=		-Dmacosx

post-patch:
	@${MV} ${WRKSRC}/guile-config/guile-config.in.orig \
	    ${WRKSRC}/guile-config/guile-config.in
.endif

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
