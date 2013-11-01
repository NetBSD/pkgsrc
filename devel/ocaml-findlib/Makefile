# $NetBSD: Makefile,v 1.18 2013/11/01 11:30:22 jaapb Exp $
#

DISTNAME=		findlib-1.4
PKGNAME=		ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=		devel
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://www.camlcity.org/
COMMENT=		Library finder for OCaml
LICENSE=		mit

USE_TOOLS+=		gmake m4 bash
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
CONFIGURE_ARGS+=	-bindir ${PREFIX}/bin
CONFIGURE_ARGS+=	-mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-config ${PKG_SYSCONFDIR}/ocamlfind.conf
CONFIGURE_ARGS+=	-sitelib ${PREFIX}/lib/ocaml/site-lib

BUILD_TARGET=		all
PLIST_SRC=		PLIST

PLIST_VARS=		opt
.include "../../mk/bsd.prefs.mk"
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=		yes
BUILD_TARGET+=		opt
.endif

EGDIR=			${PREFIX}/share/examples/ocaml-findlib
INSTALL_MAKE_FLAGS+=	OCAMLFIND_CONF=${EGDIR}/ocamlfind.conf
INSTALLATION_DIRS=	libexec bin

CONF_FILES=		${EGDIR}/ocamlfind.conf ${PKG_SYSCONFDIR}/ocamlfind.conf

USE_TOOLS+=		fgrep:run sh:run
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

post-extract:
	${CP} ${FILESDIR}/ocaml-findlib-register.sh ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ocaml-findlib-register.sh ${DESTDIR}${PREFIX}/libexec/ocaml-findlib-register

do-test:
	${RUN} cd ${WRKSRC}; ${SH} itest

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
