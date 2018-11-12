# $NetBSD: Makefile,v 1.21 2018/11/12 16:10:23 jaapb Exp $

DISTNAME=		verifast-18.02
PKGREVISION=		9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=verifast/}
GITHUB_PROJECT=		verifast
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://people.cs.kuleuven.be/~bart.jacobs/verifast/
COMMENT=		VeriFast code verifier in separation logic
LICENSE=		mit

USE_TOOLS+=		gmake pax pkg-config
MAKE_FILE=		GNUmakefile
BUILD_MAKE_FLAGS+=	-C src NUMCPU=${MAKE_JOBS}

BUILD_DEPENDS+=		vala-[0-9]*:../../lang/vala
BUILD_DEPENDS+=		camlp4-[0-9]*:../../lang/camlp4

VF_DIR=			share/verifast
INSTALLATION_DIRS=	${VF_DIR} bin
OCAML_USE_FINDLIB=	yes

do-configure:
	${CP} ${FILESDIR}/GNUmakefile.settings ${WRKSRC}/
SUBST_CLASSES+=		conf
SUBST_FILES.conf=	GNUmakefile.settings
SUBST_VARS.conf=	PREFIX OCAML_SITELIBDIR PKGVERSION_NOREV
SUBST_STAGE.conf=	post-configure

do-install:
	cd ${WRKSRC}/bin && ${FIND} . -type f -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/${VF_DIR}
	${ECHO} "#! ${SH}" > ${DESTDIR}${PREFIX}/bin/vfide
	${ECHO} '${PREFIX}/${VF_DIR}/vfide "$$@"' \
		>> ${DESTDIR}${PREFIX}/bin/vfide
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/vfide

.include "../../mk/ocaml.mk"

.include "../../lang/camlp4/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../math/z3/buildlink3.mk"
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
