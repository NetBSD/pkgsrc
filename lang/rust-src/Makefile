# $NetBSD: Makefile,v 1.6 2022/06/30 11:18:34 nia Exp $

DISTNAME=	rust-src-1.60.0
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL:=rust/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Source for the rust std library
LICENSE=	mit OR apache-2.0

USE_TOOLS+=	bash sh

LIBDIR=			lib/rustlib/src/rust/library
SRCLIB=			rust-src/${LIBDIR}
IST_TOOLS=		stdarch/crates/intrinsic-test/acle/tools
REPLACE_BASH+=		install.sh
REPLACE_BASH+=		${SRCLIB}/backtrace/ci/debuglink.sh
REPLACE_BASH+=		${SRCLIB}/stdarch/ci/dox.sh
REPLACE_BASH+=		${SRCLIB}/stdarch/ci/run-docker.sh
REPLACE_BASH+=		${SRCLIB}/stdarch/ci/run.sh
REPLACE_BASH+=		${SRCLIB}/stdarch/ci/style.sh
REPLACE_BASH+=		${SRCLIB}/${IST_TOOLS}/check-rst-syntax.sh
REPLACE_BASH+=		${SRCLIB}/${IST_TOOLS}/generate-intrinsics-specs.sh
REPLACE_BASH+=		${SRCLIB}/${IST_TOOLS}/generate-pdfs.sh

REPLACE_PYTHON+=	${SRCLIB}/core/src/unicode/printable.py
REPLACE_PYTHON+=	${SRCLIB}/${IST_TOOLS}/gen-intrinsics-specs.py

REPLACE_SH+=		${SRCLIB}/backtrace/ci/android-sdk.sh

NO_INTERPRETER+=	${SRCLIB}/backtrace/ci/android-ndk.sh
NO_INTERPRETER+=	${SRCLIB}/backtrace/ci/debuglink-docker.sh
NO_INTERPRETER+=	${SRCLIB}/backtrace/ci/miri-rustup.sh
NO_INTERPRETER+=	${SRCLIB}/backtrace/ci/run-docker.sh

ORIG_FILES+=		${LIBDIR}/std/src/sys/unix/mod.rs.orig
ORIG_FILES+=		${LIBDIR}/std/src/sys/unix/thread.rs.orig
ORIG_FILES+=		${LIBDIR}/unwind/build.rs.orig

MANIFEST=		${DESTDIR}${PREFIX}/lib/rustlib/manifest-rust-src
MANIFEST_SRC=		rust-src/manifest.in

do-build:
	# These do not have an interpreter line...
	cd ${WRKSRC}; \
	chmod -x ${NO_INTERPRETER}

do-install:
	set -e; \
	\
	cd ${WRKSRC}; \
	set -e; \
	for f in ${ORIG_FILES}; do \
		rm -f rust-src/$$f; \
		grep -v $$f <${MANIFEST_SRC} > ${MANIFEST_SRC}.new; \
		mv ${MANIFEST_SRC}.new ${MANIFEST_SRC}; \
	done; \
	env ${MAKE_ENV} \
		${TOOLS_BASH} \
		./install.sh --prefix=${DESTDIR}/${PREFIX};
	# conflicts with main rust package
	rm -f ${DESTDIR}/${PREFIX}/lib/rustlib/components;
	rm -f ${DESTDIR}/${PREFIX}/lib/rustlib/rust-installer-version;
	# fix up install manifest, remove staging ${DESTDIR}
	${SED} -e 's;file:${DESTDIR};file:;' \
		< ${MANIFEST} > ${MANIFEST}.new; \
	mv ${MANIFEST}.new ${MANIFEST}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
