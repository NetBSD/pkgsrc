# $NetBSD: Makefile,v 1.16 2021/05/24 19:53:42 wiz Exp $

PKGNAME=	pkg_distinst-0.02
PKGREVISION=	9
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Remove any distfiles not belonging to an installed package

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run
NO_BUILD=	yes
USE_LANGUAGES=	# none
AUTO_MKDIRS=	yes

SUBST_CLASSES+=		di
SUBST_STAGE.di=		do-configure
SUBST_FILES.di=		pkg_distinst.pl
SUBST_VARS.di=		PERL5
SUBST_VARS.di+=		PKGSRCDIR
SUBST_VARS.di+=		MAKE
SUBST_MESSAGE.di=	Fixing script for installation.

do-extract:
	cd ${FILESDIR} && cp pkg_distinst.pl ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_distinst.pl \
		${DESTDIR}${PREFIX}/bin/pkg_distinst

.include "../../mk/bsd.pkg.mk"
