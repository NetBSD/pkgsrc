# $NetBSD: Makefile,v 1.2 2024/11/16 12:05:53 wiz Exp $

DISTNAME=		Mail-Qmail-Queue-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
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
