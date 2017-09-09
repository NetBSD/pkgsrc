# $NetBSD: Makefile,v 1.3 2017/09/09 21:57:46 dholland Exp $

DISTNAME=		verifast-17.06
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=verifast/}
GITHUB_PROJECT=		verifast
GITHUB_TAG=		v${PKGVERSION_NOREV}

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

do-install:
	cd ${WRKSRC}/bin && ${FIND} . -type f -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/${VF_DIR}
	${ECHO} "#! ${SH}" > ${DESTDIR}${PREFIX}/bin/vfide
	${ECHO} '${PREFIX}/${VF_DIR}/vfide "$$@"' \
		>> ${DESTDIR}${PREFIX}/bin/vfide
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/vfide

.include "../../lang/camlp4/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml=	full
.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
