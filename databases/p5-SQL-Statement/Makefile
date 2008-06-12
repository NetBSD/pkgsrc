# $NetBSD: Makefile,v 1.21 2008/06/12 02:14:18 joerg Exp $
#

DISTNAME=	SQL-Statement-1.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sqs
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://
COMMENT=	Small, abstract SQL engine

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/SQL/Statement/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
