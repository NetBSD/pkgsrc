# $NetBSD: Makefile,v 1.8 2011/11/27 19:13:50 marino Exp $
#

DISTNAME=		findlib-1.2.6
PKGNAME=		ocaml-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.camlcity.org/
COMMENT=		Library finder for OCaml

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake m4
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
CONFIGURE_ARGS+=	-bindir ${PREFIX}/bin
CONFIGURE_ARGS+=	-mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-config ${PKG_SYSCONFDIR}/ocamlfind.conf

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

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
