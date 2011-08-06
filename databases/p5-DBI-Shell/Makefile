# $NetBSD: Makefile,v 1.14 2011/08/06 15:24:33 adam Exp $

DISTNAME=	DBI-Shell-11.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5dbi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBI-Shell/
COMMENT=	Interactive command Shell for the Perl DBI

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-IO-Tee>=0.64:../../devel/p5-IO-Tee
DEPENDS+=	p5-Text-Reform>=1.11:../../textproc/p5-Text-Reform

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/DBI/Shell/.packlist

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.37

REPLACE_PERL+=	lib/DBI/Shell/SQLMinus.pm

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
