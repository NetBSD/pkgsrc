# $NetBSD: Makefile,v 1.10 2022/06/28 11:31:40 wiz Exp $

DISTNAME=	Calltree-perl_pl
PKGNAME=	calltree-perl-0.1
PKGREVISION=	6
CATEGORIES=	devel
#MASTER_SITES=	http://gw55.quarry.iu.teragrid.org/mediawiki/images/3/39/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://gw55.quarry.iu.teragrid.org/mediawiki/index.php?title=Perl_Static_Source_Code_Analysis
COMMENT=	Static code analysis for perl script
LICENSE=	modified-bsd

DEPENDS+=	p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
DEPENDS+=	p5-PPI-[0-9]*:../../devel/p5-PPI
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1

REPLACE_PERL=	${DISTNAME}
USE_TOOLS+=	perl
AUTO_MKDIRS=	yes
WRKSRC=		${WRKDIR}

do-build:
	${DO_NADA}

do-install:
	${INSTALL} ${WRKDIR}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/calltree-perl.pl

.include "../../mk/bsd.pkg.mk"
