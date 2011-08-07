# $NetBSD: Makefile,v 1.3 2011/08/07 06:52:49 adam Exp $

DISTNAME=	AnyEvent-AIO-1.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AnyEvent-AIO/
COMMENT=	Perl 5 module providing truly asynchronous file and directory I/O
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/AnyEvent/AIO/.packlist

DEPENDS+=	p5-AnyEvent>=3.4:../../devel/p5-AnyEvent
DEPENDS+=	p5-IO-AIO>=3:../../devel/p5-IO-AIO

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
