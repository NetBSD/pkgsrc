# $NetBSD: Makefile,v 1.31 2022/06/28 11:35:51 wiz Exp $
#

DISTNAME=	SnortSnarf-050314.1
PKGNAME=	${DISTNAME:S/SnortSnarf-/snortsnarf-20/}
PKGREVISION=	10
CATEGORIES=	security net
MASTER_SITES=	https://www.snort.org/dl/contrib/data_analysis/snortsnarf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.silicondefense.com/software/snortsnarf/
COMMENT=	Generate HTML report summaries from snort incident alerts

DEPENDS+=	p5-Time-modules>=101.062101:../../time/p5-Time-modules

NO_BUILD=	YES

USE_TOOLS+=	pax perl:run
REPLACE_PERL=	snortsnarf.pl include/ann_xml.pl include/web_utils.pl	\
		include/xml_help.pl

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	snortsnarf.pl
SUBST_SED.paths=	-e "s|./include|${PREFIX}/share/snortsnarf|g"
SUBST_MESSAGE.paths=	Fixing paths.

INSTALLATION_DIRS=	bin share/snortsnarf share/doc/snortsnarf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snortsnarf.pl ${DESTDIR}${PREFIX}/bin/snortsnarf.pl
	cd ${WRKSRC}/include && pax -rw -pm * ${DESTDIR}${PREFIX}/share/snortsnarf
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/snortsnarf
	${INSTALL_DATA} ${WRKSRC}/Usage ${DESTDIR}${PREFIX}/share/doc/snortsnarf

.include "../../mk/bsd.pkg.mk"
