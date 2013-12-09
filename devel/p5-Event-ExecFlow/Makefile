# $NetBSD: Makefile,v 1.11 2013/12/09 14:17:44 obache Exp $

DISTNAME=	Event-ExecFlow-0.64
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.exit1.org/packages/Event-ExecFlow/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exit1.org/Event-ExecFlow/
COMMENT=	High level API for event-based execution flow control
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-AnyEvent>=0.4:../../devel/p5-AnyEvent
DEPENDS+=	{perl>=5.9.3,p5-Test-Simple>=0.62}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Locale-libintl-[0-9]*:../../misc/p5-Locale-libintl

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Event/ExecFlow/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
