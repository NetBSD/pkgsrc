# $NetBSD: Makefile,v 1.3 2013/12/09 14:17:44 obache Exp $

DISTNAME=	File-Binary-1.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~simonw/File-Binary-1.7/lib/File/Binary.pm
COMMENT=	Binary file reading module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	{perl>=5.6.2,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/File/Binary/.packlist
USE_LANGUAGES=	# none

post-install:
		${CHMOD} -x ${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/File/Binary.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
