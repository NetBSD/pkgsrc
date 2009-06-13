# $NetBSD: Makefile,v 1.2 2009/06/13 06:46:46 rillig Exp $

DISTNAME=	POE-Component-Cron-0.019
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CF/CFEDDE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?POE::Component::Cron
COMMENT=	Schedule POE Events using a cron spec

DEPENDS+=	p5-POE>=0:../../devel/p5-POE
DEPENDS+=	p5-DateTime-Event-Cron>=0:../../time/p5-DateTime-Event-Cron
DEPENDS+=	p5-DateTime-Event-Random>=0:../../time/p5-DateTime-Event-Random
DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/POE/Component/Cron/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
