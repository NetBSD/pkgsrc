# $NetBSD: Makefile,v 1.6 2014/01/31 09:04:36 obache Exp $
# -----------------------------------------------------------------------------
# Package metadata
#
DISTNAME=	ghc-${VERSION}
VERSION=	7.6.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/${VERSION}/
MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://www.haskell.org/ghc/
COMMENT=	Compiler for the functional language Haskell
LICENSE=	modified-bsd

# GHC requires GHC to build itself. Formerly we could work around this
# bootstrapping problem by creating a special archive containing C
# sources compiled from Haskell sources, but that's no longer
# possible. So we have to prepare stripped-down binaries sufficient to
# bootstrap compilers for each platforms. If you want to build them
# yourself, follow an instruction in the ./TODO file.
ONLY_FOR_PLATFORM= \
	Darwin-*-powerpc \
	FreeBSD-*-i386 \
	Linux-*-x86_64 \
	NetBSD-*-i386 \
	NetBSD-*-x86_64 \
	SunOS-5.11.*


# -----------------------------------------------------------------------------
# Distfiles
#
DISTFILES=	${DISTNAME}-src.tar.bz2
#.if make(distinfo)
#DISTFILES+=	${DISTNAME}-boot-i386-unknown-freebsd.tar.xz
#DISTFILES+=	${DISTNAME}-boot-i386-unknown-netbsd.tar.xz
#DISTFILES+=	${DISTNAME}-boot-powerpc-apple-darwin.tar.xz
#DISTFILES+=	${DISTNAME}-boot-x86_64-unknown-linux.tar.xz
#DISTFILES+=	${DISTNAME}-boot-x86_64-unknown-netbsd.tar.xz
#DISTFILES+=	${DISTNAME}-boot-i386-unknown-solaris2.tar.gz
#DISTFILES+=	${DISTNAME}-boot-x86_64-unknown-solaris2.tar.xz
#.else
#DISTFILES+=	${BOOT_ARCHIVE}
#.endif


# We don't want to extract all of the DISTFILEs.
EXTRACT_ONLY=	${DISTNAME}-src.tar.bz2


# -----------------------------------------------------------------------------
# Tools
#
USE_TOOLS+=			autoconf gmake perl:run
GNU_CONFIGURE=			yes
USE_GNU_CONFIGURE_HOST=	no

CONFIGURE_ARGS+= \
	--with-gcc=${CC:Q} \
	--with-gmp-includes=${BUILDLINK_PREFIX.gmp:Q}/include \
	--with-gmp-libraries=${BUILDLINK_PREFIX.gmp:Q}/lib \
	--with-iconv-includes=${BUILDLINK_PREFIX.iconv:Q}/include \
	--with-iconv-libraries=${BUILDLINK_PREFIX.iconv:Q}/lib

CONFIGURE_ENV+= \
	CONF_CC_OPTS_STAGE0=${CFLAGS:Q} \
	CONF_GCC_LINKER_OPTS_STAGE0=${LDFLAGS:Q} \
	CONF_LD_LINKER_OPTS_STAGE0=${LDFLAGS:Q} \
	CONF_CC_OPTS_STAGE1=${CFLAGS:Q} \
	CONF_GCC_LINKER_OPTS_STAGE1=${LDFLAGS:Q} \
	CONF_LD_LINKER_OPTS_STAGE1=${LDFLAGS:Q} \
	CONF_CC_OPTS_STAGE2=${CFLAGS:Q} \
	CONF_GCC_LINKER_OPTS_STAGE2=${LDFLAGS:Q} \
	CONF_LD_LINKER_OPTS_STAGE2=${LDFLAGS:Q} \
	PerlCmd=${PERL5:Q}


# -----------------------------------------------------------------------------
# Build hooks
#

# We patch configure.ac in some directories.
post-patch:
	@${PHASE_MSG} "Regenerating configuration scripts for ${PKGNAME}"
	${RUN} cd ${WRKSRC:Q}/libraries/integer-gmp && autoconf


# Define the target "pre-configure" and non-standard "bootstrap".
.include "../../lang/ghc7/bootstrap.mk"

.for i in ${DISTFILES:M*-boot-*}
SITES.${i}?=	${MASTER_SITE_LOCAL}
.endfor

# Our pre-configure phase installs a bindist of bootstrapping compiler
# directly into TOOLS_DIR so that ./configure can find it.
do-configure:
	${RUN} cd ${WRKSRC:Q} && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ./configure ${CONFIGURE_ARGS}

# Here we generate mk/build.mk dynamically.
	${RUN} ${RM} -f ${WRKSRC:Q}/mk/build.mk

# We need to tell the libraries/terminfo/configure that our ncurses is
# in a non-standard path. Without that, the resulting GHC tries to
# link programs by executing ld(1) without passing it -L${PREFIX:Q}/lib.
	${RUN} ${ECHO} "libraries/terminfo_CONFIGURE_OPTS += \
		--configure-option=--with-curses-includes=${BUILDLINK_PREFIX.curses:Q}/include \
		--configure-option=--with-curses-libraries=${BUILDLINK_PREFIX.curses:Q}/lib" >> ${WRKSRC:Q}/mk/build.mk

# The ghc compiler does normally split the generated asm files into small
# parts before sending them to gcc, to enable the linker to eliminate
# unused parts.  This does however not play nice with the pkgsrc
# framework, and the result is that the build takes more than 5 times
# as long than when the files are not split.  See
#    http://mail-index.netbsd.org/tech-pkg/2006/07/30/0005.html
# for a description of the problem.
# Disable file splitting until pkgsrc gets improved.
	${RUN} ${ECHO} "SplitObjs         = NO" >> ${WRKSRC:Q}/mk/build.mk

# If there is HsColour is in the PATH, GHC's build system tries to use
# it without even checking if it really works. That's not what we
# appreciate.
	${RUN} ${ECHO} "HSCOLOUR_SRCS     = NO" >> ${WRKSRC:Q}/mk/build.mk

# Don't even think of PDF.
	${RUN} ${ECHO} "BUILD_DOCBOOK_PS  = NO" >> ${WRKSRC:Q}/mk/build.mk
	${RUN} ${ECHO} "BUILD_DOCBOOK_PDF = NO" >> ${WRKSRC:Q}/mk/build.mk


# -----------------------------------------------------------------------------
# Installation/removal hooks
#

# Substitutions for INSTALL and DEINSTALL that handles package.cache.
FILES_SUBST+=	DISTNAME=${DISTNAME}

# We don't want package.cache to be in the PLIST.
post-install:
	${RM} -f ${DESTDIR:Q}${PREFIX:Q}/lib/${DISTNAME}/package.conf.d/package.cache


# -----------------------------------------------------------------------------
# PLIST
#
# We can't use static PLIST because the package installs some files
# whose names are randomly generated, namely
# lib/${PKGNAME}/package.conf.d/*.conf
#
PRINT_PLIST_AWK+=	/lib\/${PKGNAME_NOREV}\/package\.conf\.d/ { next; }

# If we were lucky we could just use "PLIST_TYPE = dynamic", but the
# feature has seemingly bitrotted.
.include "../../mk/bsd.prefs.mk"
.if empty(USE_DESTDIR:M[Yy][Ee][Ss])
GENERATE_PLIST+= \
	cd ${PREFIX:Q} && \
		${FIND} lib/${PKGNAME_NOREV}/package.conf.d -xdev -newer ${_COOKIE.extract} \! -type d -print | ${SORT} -d;
.else
GENERATE_PLIST+= \
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} lib/${PKGNAME_NOREV}/package.conf.d -xdev \! -type d -print | ${SORT} -d;
.endif


# -----------------------------------------------------------------------------
# Sanity checks
#

# There is an unused script which don't pass the portability test.
CHECK_PORTABILITY_SKIP+=	distrib/prep-bin-dist-mingw

# GHC currently *requires* ${PREFIX}/lib to be in
# "/etc/ld-elf.so.conf". See
# http://hackage.haskell.org/trac/ghc/ticket/2933
CHECK_SHLIBS_SUPPORTED=	no


# -----------------------------------------------------------------------------
# Dependencies
#

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
