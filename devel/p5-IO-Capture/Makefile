# $NetBSD: Makefile,v 1.3 2008/10/19 19:17:55 he Exp $

DISTNAME=	IO-Capture-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Capture/
COMMENT=	Perl modules to capture output to stdout and stderr

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/IO/Capture/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
