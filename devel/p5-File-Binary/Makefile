# $NetBSD: Makefile,v 1.17 2023/07/06 09:39:09 wiz Exp $

DISTNAME=	File-Binary-1.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/SIMONW/File-Binary-1.7/lib/File/Binary.pm
COMMENT=	Binary file reading module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
#DEPENDS+=	{perl>=5.6.2,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/File/Binary/.packlist
USE_LANGUAGES=	# none

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/File/Binary.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
