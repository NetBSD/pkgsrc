# $NetBSD: Makefile,v 1.10 2010/08/21 16:35:22 seb Exp $

DISTNAME=	Net-Bind-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to grovel DNS resolver information

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/Bind/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
