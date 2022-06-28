# $NetBSD: Makefile,v 1.5 2022/06/28 11:34:13 wiz Exp $

DISTNAME=		guile-1.8.8
PKGNAME=		${DISTNAME:S/guile/guile18/}
PKGREVISION=		13
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/guile/
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension (1.8 branch)
LICENSE=		gnu-lgpl-v2.1

CONFLICTS=		guile14<1.4.1nb1 guile-oops-[0-9]* guile>=1.8<2.0

GNU_CONFIGURE=		YES
GNU_CONFIGURE_STRICT=	no # has several configure programs
USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		YES
PTHREAD_AUTO_VARS=	YES
INFO_FILES=		YES
PKGCONFIG_OVERRIDE=	guile-1.8.pc.in

# Currently, all versions are namespaced.
# guile18 is hard-coded to a prefix, and does not use the scheme
# used by the others.  That is ok because guile18 will never be
# primary.
GUILE_PREFIX=			${PREFIX}/guile/1.8
GNU_CONFIGURE_PREFIX=		${GUILE_PREFIX}
BUILDLINK_PASSTHRU_DIRS+=	${GUILE_PREFIX}
LDFLAGS+=			${COMPILER_RPATH_FLAG}${GUILE_PREFIX}/lib

# XXX Make this conditional on the problematic systems.
# couldn't figure out how to work around an error on solaris-2.9/sparc with gcc when
# compiling ${WRKSRC}/libguile/filesys.c.  The warning is that readdir64_r was missing
# a prototype.
CONFIGURE_ARGS+=	--disable-error-on-warning

#CONFIGURE_ARGS+=	--without-threads

TEST_DIRS=		.
TEST_TARGET=		check

OWN_DIRS=		${PREFIX}/share/guile/site

.include "../../mk/bsd.prefs.mk"

# scmconfig.h will be rebuilt first thing.  This hack is here because
# gen-scmconfig.c includes string.h (from /usr/include) which in turn
# tries to include /usr/include/strings.h but instead the compiler picks
# up ./strings.h which tries to include scmconfig.h which doesn't exist
# yet.  While not a clean fix, this seems to work around the problem.
#
#
# for info on the slib part, see
# http://lists.gnu.org/archive/html/guile-user/2006-11/msg00035.html
post-patch:
	${TOUCH} ${WRKSRC}/libguile/scmconfig.h
	${ECHO} "(define-module (ice-9 slib))" > ${WRKSRC}/ice-9/slib.scm
	${ECHO} "(load-from-path \"slib/guile.init\")" >> ${WRKSRC}/ice-9/slib.scm

CONFIGURE_ARGS.DragonFly+=	ac_cv_type_complex_double=no

.if ${OPSYS} == "Darwin"
#This define has been reported to break builds on 10.8.
#CPPFLAGS+=		-Dmacosx

# Darwin does not use -rpath, so back out the patch that adds it.  It
# is not clear that guile works properly if directories with modules
# are not in LTDL_LIBRARY_PATH or LD_LIBRARY_PATH.  See the following
# PRs:
#   http://www.NetBSD.org/cgi-bin/query-pr-single.pl?number=33665
#   http://www.NetBSD.org/cgi-bin/query-pr-single.pl?number=36975
post-patch: post-patch-darwin
post-patch-darwin: .PHONY
	${MV} ${WRKSRC}/guile-config/guile-config.in.orig \
	    ${WRKSRC}/guile-config/guile-config.in
.endif

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
