# $NetBSD: Makefile,v 1.47 2026/03/01 12:38:19 gdt Exp $

DISTNAME=	coccinelle-1.3.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=coccinelle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://coccinelle.gitlabpages.inria.fr/website/
COMMENT=	Tool for writing and applying semantic patches
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
TOOL_DEPENDS+=	menhir>=20071212:../../devel/menhir

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config
BUILD_TARGET=	all all.opt

TEST_TARGET=	test

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

# tool is not installed, so don't install man page either
post-install:
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pycocci.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/Coccilib.3cocci \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/Coccilib.3

.include "../../lang/python/tool.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}
.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
