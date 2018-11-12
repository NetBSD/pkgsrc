# $NetBSD: Makefile,v 1.41 2018/11/12 16:10:19 jaapb Exp $

DISTNAME=		findlib-1.8.0
PKGNAME=		ocaml-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://www.camlcity.org/
COMMENT=		Library finder for OCaml
LICENSE=		mit

OCAML_FINDLIB_DIRS+=	bigarray bytes compiler-libs dynlink findlib \
			ocamldoc stdlib str threads unix

.include "../../mk/ocaml.mk"

# spacetime profiling is only available for native code on 64bit platforms
PLIST_VARS+=		64bit
.if !empty(LP64PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@) || \
    (defined(ABI) && ${ABI} == "64")
PLIST.64bit=		yes
.endif

# Undeclared dependencies between different components
MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake m4 bash fgrep:run sh:run
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-bindir ${PREFIX}/bin
CONFIGURE_ARGS+=	-mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-config ${PKG_SYSCONFDIR}/ocamlfind.conf
CONFIGURE_ARGS+=	-sitelib ${PREFIX}/${OCAML_SITELIBDIR}
CONFIGURE_ARGS+=	-no-camlp4

BUILD_TARGET=		all
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	opt
.endif

EGDIR=			${PREFIX}/share/examples/ocaml-findlib
INSTALL_MAKE_FLAGS+=	OCAMLFIND_CONF=${EGDIR}/ocamlfind.conf
INSTALLATION_DIRS=	lib/ocaml libexec bin ${OCAML_SITELIBDIR}

CONF_FILES=		${EGDIR}/ocamlfind.conf ${PKG_SYSCONFDIR}/ocamlfind.conf

FILES_SUBST+=		OCAML_FINDLIB_DIRS="${OCAML_FINDLIB_DIRS}" OCAML_SITELIBDIR="${OCAML_SITELIBDIR}"

SUBST_CLASSES+=		ofr
SUBST_STAGE.ofr=	pre-configure
SUBST_FILES.ofr=	ocaml-findlib-register.sh
SUBST_SED.ofr=		-e 's,@SH@,'${SH:Q}','
SUBST_SED.ofr+=		-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.ofr+=		-e 's,@FGREP@,'${FGREP:Q}','

SUBST_CLASSES+=		pathes
SUBST_STAGE.pathes=	post-install
SUBST_FILES.pathes=	${DESTDIR}${PREFIX}/lib/ocaml/site-lib/findlib/Makefile.config
SUBST_SED.pathes=	-e 's,^\(OCAML_CORE_BIN=\).*,\1'${PREFIX:Q}/bin','

do-test:
	${RUN} cd ${WRKSRC}; ${SH} itest

.include "../../mk/bsd.pkg.mk"
