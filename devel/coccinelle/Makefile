# $NetBSD: Makefile,v 1.42 2022/06/30 11:18:12 nia Exp $

DISTNAME=	coccinelle-1.1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=coccinelle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://coccinelle.lip6.fr/
COMMENT=	Tool for writing and applying semantic patches
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

# use included version, pkgsrc version makes ocamlopt dump core
#DEPENDS+=		menhir>=20071212:../../devel/menhir

# gmake[3]: *** No rule to make target 'stdcompat__root.cmt', needed by 'all-am'.  Stop.
MAKE_JOBS_SAFE=		no

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
