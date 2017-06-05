# $NetBSD: Makefile,v 1.10 2017/06/05 14:24:25 ryoon Exp $
#

DISTNAME=	grake-0.1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	net www
MASTER_SITES=	http://grake.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/grake/
COMMENT=	Tool for scanning webpages for Youtube video links
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-Getopt-ArgvFile>=1.11:../../devel/p5-Getopt-ArgvFile
DEPENDS+=	p5-Test-Pod>=1.44:../../devel/p5-Test-Pod
#DEPENDS+=	{perl>=5.10.1,p5-version>=0.77}:../../devel/p5-version
DEPENDS+=	p5-Umph-Prompt>=0.1.0:../../net/p5-Umph-Prompt

PERL5_PACKLIST=	auto/grake/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
