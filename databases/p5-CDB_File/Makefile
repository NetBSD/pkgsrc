# $NetBSD: Makefile,v 1.4 2010/08/21 16:32:53 seb Exp $

DISTNAME=		CDB_File-0.96
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
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
