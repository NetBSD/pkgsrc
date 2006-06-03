# $NetBSD: Makefile,v 1.1 2006/06/03 11:45:56 gavan Exp $

DISTNAME=	DB_File-Lock-0.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbfl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DB_File-Lock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module providing locking with flock wrapper for DB_File

PERL5_PACKLIST=	auto/DB_File/Lock/.packlist
DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
