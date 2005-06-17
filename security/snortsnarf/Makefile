# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:32 jlam Exp $
#

DISTNAME=	SnortSnarf-050314.1
PKGNAME=	${DISTNAME:S/SnortSnarf-/snortsnarf-20/}
CATEGORIES=	security net
MASTER_SITES=	http://www.snort.org/dl/contrib/data_analysis/snortsnarf/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.silicondefense.com/software/snortsnarf/
COMMENT=	Generate HTML report summaries from snort incident alerts

DEPENDS+=	p5-Time>=101.062101:../../time/p5-Time

NO_BUILD=	YES
USE_PERL5=	run

REPLACE_PERL=	snortsnarf.pl include/ann_xml.pl include/web_utils.pl	\
		include/xml_help.pl

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	snortsnarf.pl
SUBST_SED.paths=	-e "s|./include|${PREFIX}/share/snortsnarf|g"      
SUBST_MESSAGE.paths=	"Fixing paths."

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snortsnarf.pl ${PREFIX}/bin/snortsnarf.pl
	${INSTALL_DATA_DIR} ${PREFIX}/share/snortsnarf
	cd ${WRKSRC}/include && ${PAX} -rw -pm * ${PREFIX}/share/snortsnarf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snortsnarf
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/snortsnarf
	${INSTALL_DATA} ${WRKSRC}/Usage ${PREFIX}/share/doc/snortsnarf

.include "../../mk/bsd.pkg.mk"
