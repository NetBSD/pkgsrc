# $NetBSD: Makefile,v 1.8 2004/04/25 03:17:55 snj Exp $
#

DISTNAME=	SnortSnarf-021111.1
PKGNAME=	${DISTNAME:S/SnortSnarf-/snortsnarf-20/}
CATEGORIES=	security net
MASTER_SITES=	http://www.silicondefense.com/software/snortsnarf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.silicondefense.com/software/snortsnarf/
COMMENT=	Generate HTML report summaries from snort incident alerts

DEPENDS=	p5-Time>=101.062101:../../time/p5-Time

NO_BUILDLINK=	YES
NO_BUILD=	YES
USE_PERL5=	run

REPLACE_PERL=	snortsnarf.pl include/ann_xml.pl include/web_utils.pl	\
		include/xml_help.pl

post-configure:
	@cd ${WRKSRC} && \
		${SED} -e "s|@PREFIX@|${PREFIX}|g" snortsnarf.pl >	\
			${WRKDIR}/snortsnarf.pl

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/snortsnarf.pl ${PREFIX}/bin/snortsnarf.pl
	${INSTALL_DATA_DIR} ${PREFIX}/share/snortsnarf
	cd ${WRKSRC}/include && ${PAX} -rw -pm * ${PREFIX}/share/snortsnarf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snortsnarf
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/snortsnarf
	${INSTALL_DATA} ${WRKSRC}/Usage ${PREFIX}/share/doc/snortsnarf

.include "../../mk/bsd.pkg.mk"
