# $NetBSD: Makefile,v 1.13 2023/07/06 09:40:16 wiz Exp $

DISTNAME=	Test-NoTabs-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/BOBTFISH/Test-NoTabs-1.4/lib/Test/NoTabs.pm
COMMENT=	Check the presence of tabs in your project
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/NoTabs/.packlist

# Garbage (recursive directory ? exists after patch ?)
post-patch:
	(cd ${WRKSRC}; ${RM} -rf PaxHeader)

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
