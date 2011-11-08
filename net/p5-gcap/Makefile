# $NetBSD: Makefile,v 1.1.1.1 2011/11/08 23:50:38 ryoon Exp $
#

DISTNAME=	gcap-0.1.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://gcap.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gcap/
COMMENT=	Command line tool for retrieving Youtube closed captions
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Getopt-ArgvFile>=1.11:../../devel/p5-Getopt-ArgvFile
DEPENDS+=	p5-XML-DOM>=1.44:../../textproc/p5-XML-DOM
DEPENDS+=	p5-version>=0.77:../../devel/p5-version
DEPENDS+=	p5-Umph-Prompt>=0.1.0:../../net/p5-Umph-Prompt

PERL5_PACKLIST=	auto/gcap/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
