# $NetBSD: Makefile,v 1.44 2004/10/14 19:04:56 tv Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-base-/}
PKGREVISION=	5
SVR4_PKGNAME=	ltoob

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<=1.3.5nb11

TEST_TARGET=	check

.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS+=	--disable-shared
BUILD_SHLIBTOOL=	NO
.  endif
.endif
CONFIGURE_ARGS+=	--disable-ltdl-install
BUILD_SHLIBTOOL?=	YES

# We are going to want libtool to find the same versions of the C, C++,
# and Fortran compilers.
#
USE_LANGUAGES=		c c++ fortran
CONFIGURE_ARGS+=	--with-tags=CXX,F77,GCJ

.PHONY: fix-libtool
fix-libtool:
	cd ${WRKSRC}; for f in libtool; do				\
		${SED}	-e "s,-L${BUILDLINK_DIR}/lib,," $$f > $$f.new;	\
		if [ -x $$f ]; then ${CHMOD} +x $$f.new; fi;		\
		${MV} -f $$f.new $$f;					\
	done

post-build: fix-libtool

.if ${BUILD_SHLIBTOOL} == "NO"
PLIST_SUBST+=		SHLIBTOOL="@comment "
.else
PLIST_SUBST+=		SHLIBTOOL=

post-build:
	cd ${WRKSRC} && \
		${SED} -e '/^# Whether or not to build static/{n;s/yes/no/;}' \
		< libtool > shlibtool

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/shlibtool ${PREFIX}/bin/shlibtool
.endif

.include "../../mk/bsd.pkg.mk"
