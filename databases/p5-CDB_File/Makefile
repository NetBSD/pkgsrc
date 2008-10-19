# $NetBSD: Makefile,v 1.3 2008/10/19 19:17:43 he Exp $

DISTNAME=		CDB_File-0.96
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CDB_File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module to use CDB files

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/CDB_File/.packlist

REPLACE_PERL+=		bun-x.pl

.include "../../mk/bsd.prefs.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
