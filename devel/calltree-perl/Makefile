# $NetBSD: Makefile,v 1.2 2017/09/04 05:40:44 wiz Exp $

DISTNAME=	Calltree-perl_pl
PKGNAME=	${DISTNAME:tl:S/_pl//}-0.1
COMMAND_NAME=	${DISTNAME:tl:S/_pl/.pl/}
CATEGORIES=	devel
#MASTER_SITES=	http://gw55.quarry.iu.teragrid.org/mediawiki/images/3/39/
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://gw55.quarry.iu.teragrid.org/mediawiki/index.php?title=Perl_Static_Source_Code_Analysis
COMMENT=	Static code analysis for perl script
LICENSE=	modified-bsd

DEPENDS+=	p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+= 	p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
DEPENDS+= 	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+= 	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

REPLACE_PERL=	${DISTNAME}
USE_TOOLS+=	perl
AUTO_MKDIRS=	yes
WRKSRC=		${WRKDIR}

do-build:
	${DO_NADA}

do-install:
	(cd	${WRKDIR} ; \
	${INSTALL} ${DISTNAME} ${DESTDIR}${PREFIX}/bin/${COMMAND_NAME})

.include "../../mk/bsd.pkg.mk"
