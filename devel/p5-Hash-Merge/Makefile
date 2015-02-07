# $NetBSD: Makefile,v 1.12 2015/02/07 14:57:45 mef Exp $
#

DISTNAME=	Hash-Merge-0.200
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Hash-Merge/
COMMENT=	Perl 5 module to merges arbitrarily deep hashes
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Hash/Merge/.packlist

# Merge.pm proves this version, even if it's not named in META.yml
DEPENDS+=	p5-Clone>=0.09:../../devel/p5-Clone

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
