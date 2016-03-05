# $NetBSD: Makefile,v 1.30 2016/03/05 11:28:43 jperkin Exp $
#

DISTNAME=	basic256_0.9.6.71
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	20
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kidbasic/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.basic256.org/
COMMENT=	BASIC language with traditional control structures
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex gmake

SUBST_CLASSES+=			fix-path
SUBST_STAGE.fix-path=		pre-configure
SUBST_MESSAGE.fix-path=		Fix hard coded paths for qt4
SUBST_FILES.fix-path=		Makefile
SUBST_FILES.fix-path+=		Makefile.Release
SUBST_SED.fix-path=		-e 's,/usr/share,${PREFIX},g'
SUBST_SED.fix-path+=		-e 's,/usr/bin/qmake,${QTDIR}/bin/qmake,'
SUBST_SED.fix-path+=		-e 's,/usr/bin/moc-qt4,${QTDIR}/bin/moc,'
SUBST_SED.fix-path+=		-e 's,/usr/bin/rcc,${QTDIR}/bin/rcc,'
SUBST_SED.fix-path+=		-e 's,-I/usr/include/qt4,-I${QTDIR}/include,g'

SUBST_CLASSES+=			fix-path2
SUBST_STAGE.fix-path2=		pre-configure
SUBST_MESSAGE.fix-path2=	Fix hard coded paths
SUBST_FILES.fix-path2+=		BASIC256.pro
SUBST_SED.fix-path2=		-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.fix-path2+=		-e 's,/usr/local,${PREFIX},g'

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/espeak/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
