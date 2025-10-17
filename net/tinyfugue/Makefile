# $NetBSD: Makefile,v 1.39 2025/10/17 22:07:48 mrg Exp $

DISTNAME=	tf-40s1
PKGNAME=	tf-4.0s1
PKGREVISION=	9
CATEGORIES=	net games
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=tinyfugue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinyfugue.sourceforge.net/
COMMENT=	Popular programmable MUD client, with macro support and more

MAKE_JOBS_SAFE=		no

MAKE_FILE=	${WRKSRC}/unix/Makefile
MAKE_ENV+=	TFVER=${DISTNAME:S/^tf-//}

PATCH_SITES=		http://discworld.imaginary.com/external/taffyd/
PATCHFILES=		tf-40s1-mccp-patch.gz
PATCH_DIST_STRIP=	-p1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=			fix-paths
SUBST_MESSAGE.fix-paths=	late-addition DESTDIR
SUBST_STAGE.fix-paths=		pre-configure
SUBST_FILES.fix-paths=		unix/Config
SUBST_VARS.fix-paths=		DESTDIR

LDFLAGS.SunOS+=	-lz

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-14.*) || !empty(CC_VERSION:Mgcc-15.*)
CFLAGS+=	-Wno-implicit-int -Wno-implicit-function-declaration 
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
