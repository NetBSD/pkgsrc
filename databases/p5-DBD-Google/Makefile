# $NetBSD: Makefile,v 1.16 2011/08/06 20:05:05 adam Exp $

DISTNAME=	DBD-Google-0.51
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5 www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-Google/
COMMENT=	Perl DBI/DBD driver for using Google as a datasource

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DBI>=1.5:../../databases/p5-DBI
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-Net-Google>=0.61:../../net/p5-Net-Google
DEPENDS+=	p5-SQL-Statement>=1.00:../../databases/p5-SQL-Statement
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

PERL5_PACKLIST=		auto/DBD/Google/.packlist

BUILDLINK_API_DEPENDS.p5-DBI?=	p5-DBI>=1.39

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
