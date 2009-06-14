# $NetBSD: Makefile,v 1.1.1.1 2009/06/14 22:42:57 sno Exp $
#

DISTNAME=	Template-DBI-2.64
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-DBI/
COMMENT=	Template interface to the DBI module
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Template-Toolkit>=2.15:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Tie-DBI-[0-9]*:../../databases/p5-Tie-DBI

PERL5_PACKLIST=		auto/Template/DBI/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
