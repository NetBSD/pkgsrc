# $NetBSD: Makefile,v 1.5 2010/08/21 16:33:01 seb Exp $

DISTNAME=	DB_File-Lock-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5dfl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DB_File-Lock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module providing locking with flock wrapper for DB_File

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/DB_File/Lock/.packlist
DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
