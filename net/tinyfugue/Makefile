# $NetBSD: Makefile,v 1.33 2017/01/19 18:52:21 agc Exp $

DISTNAME=	tf-40s1
PKGNAME=	tf-4.0s1
PKGREVISION=	9
CATEGORIES=	net games
MASTER_SITES=	ftp://laurel.actlab.utexas.edu/pub/tinyfugue/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=tinyfugue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinyfugue.sourceforge.net/
COMMENT=	Popular programmable MUD client, with macro support and more

MAKE_JOBS_SAFE=		no

MAKE_FILE=	${WRKSRC}/unix/Makefile
MAKE_ENV+=	TFVER=${DISTNAME:S/^tf-//}

PATCH_SITES=	http://discworld.imaginary.com/external/taffyd/
PATCHFILES=	tf-40s1-mccp-patch.gz
PATCH_DIST_STRIP=-p1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=			fix-paths
SUBST_MESSAGE.fix-paths=	late-addition DESTDIR
SUBST_STAGE.fix-paths=		pre-configure
SUBST_FILES.fix-paths=		unix/Config
SUBST_SED.fix-paths=		-e 's,@DESTDIR@,'${DESTDIR}',g'

LDFLAGS.SunOS+=	-lz

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
