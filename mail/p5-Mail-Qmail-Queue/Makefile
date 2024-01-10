# $NetBSD: Makefile,v 1.1 2024/01/10 16:45:16 schmonz Exp $

DISTNAME=		Mail-Qmail-Queue-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GI/GIFF/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://metacpan.org/dist/Mail-Qmail-Queue
COMMENT=		Modules to talk to and/or help replace qmail-queue
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Mail/Qmail/Queue/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
