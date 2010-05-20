# $NetBSD: Makefile,v 1.5 2010/05/20 18:11:39 drochner Exp $
#

DISTNAME=	Event-ExecFlow-0.64
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.exit1.org/packages/Event-ExecFlow/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exit1.org/Event-ExecFlow/
COMMENT=	High level API for event-based execution flow control

DEPENDS+=	p5-AnyEvent>=0.4:../../devel/p5-AnyEvent
DEPENDS+=	p5-Test-Simple>=0.62:../../devel/p5-Test-Simple
DEPENDS+=	p5-Locale-libintl-[0-9]*:../../misc/p5-Locale-libintl

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Event/ExecFlow/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
