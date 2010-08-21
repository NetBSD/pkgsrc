# $NetBSD: Makefile,v 1.2 2010/08/21 16:33:53 seb Exp $
#

DISTNAME=	IO-Pipeline-0.009002
PKGNAME=	p5-IO-Pipeline-0.9.2
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Pipeline/
COMMENT=	Perl 5 module providing map and grep for filehandles, unix pipe style
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Pipeline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
