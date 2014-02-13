# $NetBSD: Makefile,v 1.7 2014/02/13 17:35:44 abs Exp $

DISTNAME=	pkg_p5up2date-0.04
PKGREVISION=	3
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-p5-people@NetBSD.org
COMMENT=	Check p5-* pkgsrc packages requiring updates

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_TOOLS+=	perl:run

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

DEPENDS+=	p5-File-Find-Rule>=0.30:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-CPAN-DistnameInfo>=0.02:../../devel/p5-CPAN-DistnameInfo

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	pre-configure
SUBST_MESSAGE.tools=	Substituting tool locations.
SUBST_FILES.tools=	pkg_p5up2date.pl
SUBST_VARS.tools=	PKG_INFO_CMD MAKE PERL5

SUBST_CLASSES+=		pkgsrcdir
SUBST_STAGE.pkgsrcdir=	pre-configure
SUBST_MESSAGE.pkgsrcdir=Recording default path of pkgsrc base directory.
SUBST_FILES.pkgsrcdir=	pkg_p5up2date.pl
SUBST_SED.pkgsrcdir=	-e 's,@PKGSRCDIR@,${PKGSRCDIR},g'

# REPLACE_PERL+=		pkg_p5up2date.pl

.include "../../mk/bsd.prefs.mk"

do-extract:
	cp ${FILESDIR}/pkg_p5up2date.pl ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_p5up2date.pl \
		${DESTDIR}${PREFIX}/bin/pkg_p5up2date
	pod2man ${DESTDIR}${PREFIX}/bin/pkg_p5up2date \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/pkg_p5up2date.8

.include "../../mk/bsd.pkg.mk"
