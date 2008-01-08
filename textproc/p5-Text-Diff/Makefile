# $NetBSD: Makefile,v 1.11 2008/01/08 20:48:18 heinz Exp $

DISTNAME=	Text-Diff-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High-level text diffing module for Perl

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Algorithm-Diff>=1.15:../../devel/p5-Algorithm-Diff

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Text/Diff/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
