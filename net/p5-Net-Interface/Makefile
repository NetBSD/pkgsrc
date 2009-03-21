# $NetBSD: Makefile,v 1.1.1.1 2009/03/21 13:50:18 sno Exp $

DISTNAME=	Net-Interface-1.010
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/${DISTNAME}
COMMENT=	Perl extension to access network interfaces

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/Interface/.packlist

REPLACE_PERL+=		inst/netsymbols.pl

pre-configure:
	@${FIND} ${WRKSRC} -name '*.orig' -print -type f | ${XARGS} ${RM} -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
