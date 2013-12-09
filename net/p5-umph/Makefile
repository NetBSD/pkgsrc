# $NetBSD: Makefile,v 1.6 2013/12/09 14:17:50 obache Exp $
#

DISTNAME=	umph-0.2.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://umph.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/umph/
COMMENT=	Command line tool for parsing video links from Youtube feeds
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-Getopt-ArgvFile>=1.11:../../devel/p5-Getopt-ArgvFile
DEPENDS+=	p5-XML-DOM>=1.44:../../textproc/p5-XML-DOM
DEPENDS+=	{perl>=5.10.1,p5-version>=0.77}:../../devel/p5-version
DEPENDS+=	p5-Umph-Prompt>=0.1.0:../../net/p5-Umph-Prompt

PERL5_PACKLIST=	auto/umph/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
