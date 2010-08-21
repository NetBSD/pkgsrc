# $NetBSD: Makefile,v 1.15 2010/08/21 16:32:51 seb Exp $
#

DISTNAME=	Unicode-String-2.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-String/
COMMENT=	Perl5 modules to handle various Unicode issues

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		auto/Unicode/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
