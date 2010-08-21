# $NetBSD: Makefile,v 1.3 2010/08/21 16:34:11 seb Exp $
#

DISTNAME=	Object-Declare-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Object-Declare/
COMMENT=	Perl 5 module providing declarative object constructor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Object/Declare/.packlist

DEPENDS+=	p5-Sub-Override-[0-9]*:../../devel/p5-Sub-Override

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
