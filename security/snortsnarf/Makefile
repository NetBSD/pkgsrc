# $NetBSD: Makefile,v 1.1.1.1 2002/07/12 16:38:53 agc Exp $
#

DISTNAME=	SnortSnarf-020516.1
PKGNAME=	snortsnarf-20020516.1
CATEGORIES=	security net
MASTER_SITES=	http://www.silicondefense.com/software/snortsnarf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.silicondefense.com/software/snortsnarf/
COMMENT=	Generate HTML report summaries from snort incident alerts

DEPENDS+=	p5-Time:../../time/p5-Time

USE_PERL5=	YES
REPLACE_PERL=	${WRKSRC}/snortsnarf.pl
NO_BUILD=	# defined

post-configure:
	@cd ${WRKSRC} ; \
	${SED} -e "s|@@PREFIX@@|${PREFIX}|g" snortsnarf.pl > snortsnarf.tmp ; \
	${MV} snortsnarf.tmp snortsnarf.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/snortsnarf.pl ${PREFIX}/bin/snortsnarf.pl
	${INSTALL_DATA_DIR} ${PREFIX}/share/snortsnarf/SnortSnarf
.for f in IPAddrContact.pm ann_xml.pl web_utils.pl xml_help.pl
		${INSTALL_DATA} ${WRKSRC}/include/${f} \
			${PREFIX}/share/snortsnarf
.endfor
.for f in AlertBase.pm HTMLOutput.pm MemTimeBase.pm MultiStore.pm \
	MemPacket.pm HTMLMemStorage.pm Filtering.pm PacketBase.pm \
	AllMods.pm BasicFilters.pm KnownEquiv.pm SnortFileInput.pm \
	HTMLAnomMemStorage.pm Input.pm SorterBase.pm Sort.pm \
	StorageBase.pm MemAlert.pm BasicSorters.pm Filter.pm \
	SnortRules.pm MemStorage.pm SnortDBInput.pm TimeFilters.pm
	${INSTALL_DATA} ${WRKSRC}/include/SnortSnarf/${f} \
		${PREFIX}/share/snortsnarf/SnortSnarf
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/snortsnarf
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/snortsnarf
	${INSTALL_DATA} ${WRKSRC}/Usage ${PREFIX}/share/doc/snortsnarf

.include "../../mk/bsd.pkg.mk"
