# $NetBSD: Makefile,v 1.4 2010/08/21 16:33:51 seb Exp $

DISTNAME=	IO-Capture-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-Capture/
COMMENT=	Perl modules to capture output to stdout and stderr

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/IO/Capture/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
