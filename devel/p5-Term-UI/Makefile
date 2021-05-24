# $NetBSD: Makefile,v 1.11 2021/05/24 19:51:39 wiz Exp $

DISTNAME=	Term-UI-0.46
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Term::UI
COMMENT=	Methods to ask both elaborate questions and simple yes/no
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Log-Message-Simple-[0-9]*:../../devel/p5-Log-Message-Simple
BUILD_DEPENDS+=	p5-Log-Message-[0-9]*:../../devel/p5-Log-Message

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Term/UI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
