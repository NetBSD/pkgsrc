# $NetBSD: Makefile,v 1.2 2007/04/14 18:08:01 xtraeme Exp $
#

DISTNAME=	Event-ExecFlow-0.63
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.exit1.org/packages/Event-ExecFlow/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exit1.org/Event-ExecFlow/
COMMENT=	High level API for event-based execution flow control

DEPENDS+=	p5-AnyEvent>=0.4:../../devel/p5-AnyEvent
DEPENDS+=	p5-Test-Simple>=0.62:../../devel/p5-Test-Simple
DEPENDS+=	p5-Locale-libintl-[0-9]*:../../misc/p5-Locale-libintl

PERL5_PACKLIST=	auto/Event/ExecFlow/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
