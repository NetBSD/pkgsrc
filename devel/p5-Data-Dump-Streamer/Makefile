# $NetBSD: Makefile,v 1.1.1.1 2008/08/02 07:58:24 seb Exp $
#

DISTNAME=		Data-Dump-Streamer-2.08-40
PKGNAME=		p5-${DISTNAME:C/-([0-9]*)$/.\1/}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-Dump-Streamer/
COMMENT=		Perl 5 module to serialize a data structure as Perl

MAKE_PARAMS+=		NODDS
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-B-Utils>=0.05:../../devel/p5-B-Utils

PERL5_PACKLIST=		auto/Data/Dump/Streamer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
