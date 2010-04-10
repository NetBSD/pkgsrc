# $NetBSD: Makefile,v 1.1.1.1 2010/04/10 13:43:01 seb Exp $

DISTNAME=	Server-Starter-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Server-Starter/
COMMENT=	Perl 5 superdaemon for hot-deploying server programs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Server/Starter/.packlist

BUILD_DEPENDS+=	p5-Test-TCP>=0.11:../../net/p5-Test-TCP
DEPENDS+=	p5-Proc-Wait3-[0-9]*:../../devel/p5-Proc-Wait3

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
